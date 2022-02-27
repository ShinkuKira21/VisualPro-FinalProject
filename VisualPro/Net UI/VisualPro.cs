using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace VP_UI
{
    public partial class VisualPro : Form
    {
        protected IntPtr xml, memory;
        protected Actions actions;
        protected VP_Tools.Cache cache;
        protected List<VP_Tools.Cache> objects;
        protected VP_Tools.Manager man;

        public VisualPro()
        {
            InitializeComponent();

            /* How far off? 3 more calls
             * Update: 1 more call :)
             * Managed to load the languages and LanguageCompiler is now ready to function.
             * File Explorer and Libraries are required.
             */
            /* Todo Next: Wire up plan */
            xml = VP_Comms.Decoder.InitialiseXMLClass("conf-xml", "conf.xml"); // Initialises XML
            memory = VP_Comms.Decoder.InitialisePlannerClass(); //Initialises Planner
            LoadLanguages();

            man = new VP_Tools.Manager(VP_Configuration.General.signatures);
            objects = new List<VP_Tools.Cache>();
            actions = new Actions(ref StaticMemory.memory);
        }

        private void DragStart(object sender, MouseEventArgs e)
        {
            cache = new VP_Tools.Cache() { Obj = sender };
            actions = new Actions(ref StaticMemory.memory, cache);

            ((Button)cache.Obj).DoDragDrop(((Button)cache.Obj).Text, DragDropEffects.Copy | DragDropEffects.Move);
        }

        private void WorkareaDragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
                e.Effect = DragDropEffects.Copy;
        }

        private void WorkareaDragEnd(object sender, DragEventArgs e)
        {
            Button obj = (Button)cache.Obj;

            // Only parent's can be classes or functions.
            man.Add(obj.Text, new[] { "", "", "", "" });

            man.GetList(obj.Text);

            // Tells ToolComponents of current objects
            VP_Objects.ToolComponents tc = new VP_Objects.ToolComponents(objects, ref sender, 0); // using the manager length here is bad :(

            objects.Add(new VP_Tools.Cache());
            objects[objects.Count - 1].Obj = tc.Add(obj.Text, 0);

            actions = new Actions(ref StaticMemory.memory, man);
        }

        private void VisualPro_FormClosing(object sender, FormClosingEventArgs e)
        {
            // Deconstruct on Form Closing
            VP_Comms.Decoder.DisposeXMLClass(xml);
            VP_Comms.Decoder.DisposePlannerClass(memory);
        }

        private void btnSaveCode_Click(object sender, EventArgs e)
        {
            if (bxALanguages.SelectedItem != null)
            {
                IntPtr ts = VP_Comms.Libraries.InitialiseTS();
                string libraries = Marshal.PtrToStringAnsi(VP_Comms.Decoder.SendCommand(ts, xml, "4c4150", (string)bxALanguages.SelectedItem));
                string syntaxes =
                    Marshal.PtrToStringAnsi(VP_Comms.Decoder.SendCommand(ts, xml, "4c4153",
                        (string)bxALanguages.SelectedItem));

                string library;
                for(int i = 0; (library = Marshal.PtrToStringAnsi(VP_Comms.Libraries.FindSubStr(ts, libraries, i, '\x1f'))) != null; i++) VP_Configuration.General.AddLanguageHeader(library);

                string syntax;
                for(int i = 0; (syntax = Marshal.PtrToStringAnsi(VP_Comms.Libraries.FindSubStr(ts, syntaxes, i, '\x1f'))) != null; i++) VP_Configuration.General.AddLanguageSyntax(syntax);

                VP_Comms.Libraries.DisposeTS(ts);

                string data = man.CompileCode(xml, (string)bxALanguages.SelectedItem);

                if (dialog_saveFile.ShowDialog() == DialogResult.OK)
                {
                    string path = System.IO.Path.GetFullPath(dialog_saveFile.FileName);
                    VP_Comms.Libraries.FileController("707574", data, path);
                }
            }
        }

        private void LoadLanguages()
        {
            /* Configure Available Languages Available within the Application */
            IntPtr ts = VP_Comms.Libraries.InitialiseTS(); //Temporary storage

            string availableLanguages = Marshal.PtrToStringAnsi(VP_Comms.Decoder.SendCommand(ts, xml, "4c414c"));

            if (availableLanguages == null)
            {
                // Needs looking at
                Hide();
                Form errDialog = new Error_Dialog();
                errDialog.Show();
            }
            /* End of Configuration */

            if (availableLanguages != null)
            {
                string language;
                for (int i = 0; (language = Marshal.PtrToStringAnsi(VP_Comms.Libraries.FindSubStr(ts, availableLanguages, i, '\x1f'))) != null; i++)
                    bxALanguages.Items.Insert(i, language);
            }

            VP_Comms.Libraries.DisposeTS(ts);
        }
    }
}