using System;
using System.Collections.Generic;
using System.Windows.Forms;
using VP_Tools;

namespace VP_UI
{
    public static class StaticMemory
    { public static Memory memory = new Memory(); }

    public class Memory
    { public Actions ActionMemory { get; set; } }

    public class Actions : Form
    {
        private readonly Actions actions;
        protected Cache cache, extCache;
        protected List<Cache> objects;
        protected Manager man;

        // Use for storing objects and manager to memory class.
        public Actions()
        { objects = new List<Cache>(); }

        // Use for initialising Actions on program start
        public Actions(ref Memory memory)
        { memory.ActionMemory = new Actions(); }

        // Use for storing latest cache for start drag
        public Actions(ref Memory memory, Cache cache)
        { memory.ActionMemory.cache = cache; }

        // Use for storing latest statistics after last drag
        public Actions(ref Memory memory, Manager manager)
        { memory.ActionMemory.man = manager; }

        // Use for getting current statistics after last drag
        public Actions(ref Memory memory, object obj, string type = "")
        {
            cache = new Cache(); extCache = new Cache();
            actions = memory.ActionMemory;
            extCache.Obj = obj; extCache.Text = type;
        }

        // Events \\

        public void ParentDragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
                e.Effect = DragDropEffects.Copy;
        }

        public void ParentDragEnd(object sender, DragEventArgs e)
        {
            Button obj = (Button)actions.cache.Obj;
            VP_Tools.Tools tool = new VP_Tools.Tools();
            string par = tool.FindSubStr('-', '\0', 1, ((Panel)sender).Name); // Parent ID

            int pID = VP_Configuration.General.GetID(tool.FindSubStr('-', '-', 1, ((Panel)sender).Name));
            int cID = VP_Configuration.General.GetID(obj.Text[0]);

            if (cID > pID && cID != 2)
            {
                if (extCache.Text == "label") ((Label)extCache.Obj).Text = "";

                System.Console.WriteLine(obj.Text);
                actions.man.Add(obj.Text, new string[] { "", "", "", par });
                actions.man.GetList(obj.Text);

                // OBJECTS WILL HAVE THEIR OWN COUNT - (ACTIONS MAY NEED IT'S OWN MEMORY) (Update: It did!)
                // Tells ToolComponents of current objects
                VP_Objects.ToolComponents tc = new VP_Objects.ToolComponents(actions.objects, ref sender, 0);


                actions.objects.Add(new VP_Tools.Cache());
                actions.objects[actions.objects.Count - 1].Obj = tc.Add(obj.Text, 2);
            }
        }

        public void ClearTextBox(object sender, EventArgs e)
        {
            if (((TextBox)sender).ForeColor == System.Drawing.SystemColors.ControlDark)
            {
                // Resets TextBox to blank and resets colour to default
                ((TextBox)sender).Text = "";
                ((TextBox)sender).ResetForeColor();
            }
        }

        public void EditPlan(object sender, EventArgs e)
        { 
            if(((TextBox)sender).Text != null)
            {
                // logic enters here
            }
        }

        public void PropertyWindow(object sender, EventArgs e)
        { new Property().Show(); }

        public void RemoveContainer(object sender, EventArgs e)
        { 
            Tools tool = new Tools();
            string signature = tool.FindSubStr('-', '-', 1, ((Button)sender).Name);
            string id = tool.FindSubStr('-', '\0', 2, ((Button)sender).Name);

            actions.man.Remove(actions.man.FindSignature(signature), Int32.Parse(id));

            VP_Objects.ToolComponents tc = new VP_Objects.ToolComponents(actions.objects, ref sender, 0);

            tc.Remove(sender, 1);
        }
    }
}