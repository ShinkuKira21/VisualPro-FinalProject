using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Windows.Forms;
using VP_UI;

//1\\             //0\\                     //00\\
/* Sometimes you need the future to see the past, the past to see the present and the present to see the future */ 
// -- Quote by Edward Patch. 

namespace VP_Objects
{
    public class Objects : Form
    {
        protected object parent;
        protected int type;
 
        public Objects()
        { parent = null; type = -1; }

        protected virtual void AddObject(object layout, int type = 0)
        {
            if (type == 0)
            {
                ((Panel)parent).Controls.Add((Panel)layout);
                ((Panel)layout).ResumeLayout(false);
                ((Panel)layout).PerformLayout();
            }
        }

        protected virtual void RemoveObject(object obj, int type = 0)
        {
            // Button
            if(type == 1)
            {
                // Error: If removed, the addition technique to position the objects
                //          doesn't fundamentally do two things, recheck what positions
                //          occupied and doesn't reposition on the recheck process.
                //          Error Level: 4 - Intermediate, doesn't affect the functionality
                //          But does affect user usability.
                // https://www.extensionmethod.net/csharp/control/findparent
                // https://docs.microsoft.com/en-us/dotnet/api/system.windows.forms.control.parent?view=windowsdesktop-6.0
                Control parentControl = ((Button)obj).Parent;
                parentControl.Parent.Controls.Remove(parentControl);
                
            }
        }
    }

    public class ToolComponents : Objects
    {
        protected int[,] points; 
        readonly VP_Tools.Cache[] currentObjs;
        object component;

        public ToolComponents(List<VP_Tools.Cache> currentObjs, ref object parent, int type)
        {
            this.currentObjs = currentObjs.ToArray();
            this.parent = parent; this.type = type;

            if(type == 0)
                component = new Panel();
        }

        public object Add(string name, int selection)
        {
            component = LayoutConstruction(name, selection);
            AddObject(component, type);

            return component;
        }

        public void Remove(object obj, int type = 0)
        {
            RemoveObject(obj, type);
        }

        object LayoutConstruction(string name, int selection)
        {
            Containers containers = new Containers(name, selection, currentObjs.Length + 1);

            if (selection == 0)
            {
                RePositionExistingObjects();
                return containers.DefaultContainer();
            }


            if (selection == 1)
            {
                RePositionExistingObjects();
                return containers.SecondaryContainer();
            }

            return containers.ChildContainer();
        }
        
        void RePositionExistingObjects()
        {
            // this creates a dynamic design of how the objects position within the workarea.
            int type;
            int[] newOrigin;

            if(currentObjs.Length == 1)
            {
                type = FindOutType(((Panel)currentObjs[0].Obj).Name);
                points = LocSize.GetPoints(type);
                newOrigin = LocSize.PointGenerator(type, currentObjs.Length, true);

                if (type == 0)
                    ((Panel)currentObjs[0].Obj).Location = new System.Drawing.Point(points[0, 0] + newOrigin[0], points[0, 1] + newOrigin[1]);
            }               
        }

        int FindOutType(string name)
        {
            string type = "";

            for (int i = 3; name[i] != '-'; i++)
                type += name[i];

            if (type == "DC") return 0;
            return 1;
        }
    }

    public class Containers : Objects
    {
        protected int[,] sizes, points;

        private readonly Panel panel;
        private readonly List<Panel> subPanels;
        private readonly List<Button> subButtons;
        private readonly List<Label> subLabels;
        private readonly List<TextBox> subTextBoxes;
        private readonly List<GroupBox> subGroupBoxes;
        private readonly int size; private readonly string tool;
        private Actions actions;

        public Containers(string tool, int type, int size)
        {
            this.size = size; this.tool = tool; this.type = type;


            // Initialises for all
            actions = new Actions();

            points = LocSize.GetPoints(type);
            sizes = LocSize.GetSizes(type);

            panel = new Panel();
            panel.SuspendLayout();

            subPanels = new List<Panel>();
            subLabels = new List<Label>();
            subTextBoxes = new List<TextBox>();
            subButtons = new List<Button>();
            subGroupBoxes = new List<GroupBox>();
        }

        // IDs: DC - DefaultContainer, SC - SecondaryContainer and CC - Child Container
        public object DefaultContainer()
        {
            int[] newOrigin = LocSize.PointGenerator(type, size);

            /* INITIALISATION */

            // Sub-Panels
            for (int i = 0; i < 2; i++)
            {
                subPanels.Add(new Panel());
                subPanels[i].SuspendLayout();
            }

           

            // Sub-TextBoxes
            for (int i = 0; i < 3; i++)
            {
                subTextBoxes.Add(new TextBox());
                subTextBoxes[i].SuspendLayout();
            }

            // Sub-Buttons
            for (int i = 0; i < 2; i++)
            {
                subButtons.Add(new Button());
                subButtons[0].SuspendLayout();
            }

            // Sub-Labels
            for (int i = 0; i < 3; i++)
            {
                subLabels.Add(new Label());
                subLabels[i].SuspendLayout();

                if (i == 2)
                    actions = new VP_UI.Actions(ref VP_UI.StaticMemory.memory, subLabels[i], "label");
            }

            // Sub-GroupBoxes
            subGroupBoxes.Add(new GroupBox());
            subGroupBoxes[0].SuspendLayout();

            /* DESIGN */

            // pnlSubComponent
            panel.Controls.Add(subPanels[0]);
            panel.Controls.Add(subTextBoxes[0]);

            for(int i = 0; i < 2; i++)
                panel.Controls.Add(subButtons[i]);

            panel.AutoSize = true;
            panel.Location = new System.Drawing.Point(points[0,0] + newOrigin[0], points[0,1] + newOrigin[1]); // CHANGE - REFER TO VISUAL PRO REF
            panel.MinimumSize = new System.Drawing.Size(sizes[0, 0], sizes[0, 1]);
            panel.Name = "pnlDC-SubComponent-" + size;
            panel.Size = new System.Drawing.Size(sizes[0,0], sizes[0,1]); // CHANGE - REFER TO VISUAL PRO REF
            panel.TabIndex = 6;

            // pnlContainer - 0
            for (int i = 1; i <= 2; i++)
            {
                subPanels[0].Controls.Add(subTextBoxes[i]);
                subPanels[0].Controls.Add(subLabels[i - 1]);
            }

            subPanels[0].Controls.Add(subGroupBoxes[0]);

            subPanels[0].AutoSize = true;
            subPanels[0].BorderStyle = BorderStyle.FixedSingle;
            subPanels[0].Location = new System.Drawing.Point(points[1,0], points[1,1]);
            subPanels[0].MinimumSize = new System.Drawing.Size(sizes[1, 0], sizes[1, 1]);
            subPanels[0].Name = "pnlDC-Container-" + size;
            subPanels[0].Size = new System.Drawing.Size(sizes[1,0], sizes[1,1]);
            subPanels[0].TabIndex = 1;

            // tb_name - 0
            subTextBoxes[0].ForeColor = System.Drawing.SystemColors.ControlDark;
            subTextBoxes[0].Location = new System.Drawing.Point(points[6, 0], points[6, 1]);
            subTextBoxes[0].Name = "tbDC-Name" + size;
            subTextBoxes[0].Size = new System.Drawing.Size(sizes[5, 0], sizes[5, 1]);
            subTextBoxes[0].TabIndex = 0;
            subTextBoxes[0].Text = tool + " Name...";
            subTextBoxes[0].Click += actions.ClearTextBox;
            subTextBoxes[0].TextChanged += actions.ClearTextBox;

            // Property Button (controls properties)
            subButtons[0].Enabled = false;
            subButtons[0].Location = new System.Drawing.Point(points[10, 0], points[10, 1]);
            subButtons[0].Name = "btnDC-Properties-" + size;
            subButtons[0].Size = new System.Drawing.Size(sizes[9, 0], sizes[9, 1]);
            subButtons[0].TabIndex = 2;
            subButtons[0].Text = "Properties";
            subButtons[0].UseVisualStyleBackColor = true;

            if (tool == "Function")
            {
                subButtons[0].Enabled = true;
                subButtons[0].Click += actions.PropertyWindow;
            }

            // Remove Button
            subButtons[1].Image = VP_UI.Properties.Resources.x_s1;
            subButtons[1].Location = new System.Drawing.Point(points[11, 0], points[11, 1]);
            subButtons[1].Name = "btnDC-Remove-" + tool[0] + "-" + size;
            subButtons[1].Size = new System.Drawing.Size(sizes[10, 0], sizes[10, 1]);
            subButtons[1].TabIndex = 3;
            subButtons[1].UseVisualStyleBackColor = true;

            subButtons[1].Click += actions.RemoveContainer;

            // tb_member - 1
            subTextBoxes[1].Location = new System.Drawing.Point(points[3, 0], points[3, 1]);
            subTextBoxes[1].Name = "tbDC-Member-" + size;
            subTextBoxes[1].Size = new System.Drawing.Size(sizes[2, 0], sizes[2, 1]);
            subTextBoxes[1].TabIndex = 2;

            // tb_datatype - 2
            subTextBoxes[2].Location = new System.Drawing.Point(points[2, 0], points[2, 1]);
            subTextBoxes[2].Name = "tbDC-DataType-" + size;
            subTextBoxes[2].Size = new System.Drawing.Size(sizes[2, 0], sizes[2, 1]);
            subTextBoxes[2].TabIndex = 3;

            // lblMember - 0
            subLabels[0].AutoSize = true;
            subLabels[0].Location = new System.Drawing.Point(points[5, 0], points[5, 1]);
            subLabels[0].Name = "lblDC-Member-" + size;
            subLabels[0].Size = new System.Drawing.Size(sizes[4, 0], sizes[4, 1]);
            subLabels[0].TabIndex = 2;
            subLabels[0].Text = "Member:";

            // lblDataType - 1
            subLabels[1].AutoSize = true;
            subLabels[1].Location = new System.Drawing.Point(points[4, 0], points[4, 1]);
            subLabels[1].Name = "lblDC-DataType-" + size;
            subLabels[1].Size = new System.Drawing.Size(sizes[4, 0], sizes[4, 1]);
            subLabels[1].TabIndex = 1;
            subLabels[1].Text = "Data-Type:";

            // gb_children - 0
            subGroupBoxes[0].Controls.Add(subPanels[1]);

            subGroupBoxes[0].AutoSize = true;
            subGroupBoxes[0].Location = new System.Drawing.Point(points[7, 0], points[7, 1]);
            subGroupBoxes[0].MinimumSize = new System.Drawing.Size(sizes[6, 0], sizes[6, 1]);
            subGroupBoxes[0].Name = "gbDC-children-" + size;
            subGroupBoxes[0].Size = new System.Drawing.Size(sizes[6, 0], sizes[6, 1]);
            subGroupBoxes[0].TabIndex = 4;
            subGroupBoxes[0].TabStop = false;
            subGroupBoxes[0].Text = "Children";

            // pnlChildren - 1
            subPanels[1].Controls.Add(subLabels[2]);

            subPanels[1].AllowDrop = true;
            subPanels[1].AutoSize = true;
            subPanels[1].Dock = DockStyle.Fill;
            subPanels[1].Location = new System.Drawing.Point(points[8, 0], points[8, 1]);
            subPanels[1].MinimumSize = new System.Drawing.Size(sizes[7, 0], sizes[7, 1]);
            subPanels[1].Name = "pnlDC-Children-" + tool[0] + "-" + size;
            subPanels[1].Size = new System.Drawing.Size(sizes[7, 0], sizes[7, 1]);
            subPanels[1].TabIndex = 1;

            subPanels[1].DragEnter += actions.ParentDragEnter;
            subPanels[1].DragDrop += actions.ParentDragEnd;

            // lblDragDrop - 2
            subLabels[2].AllowDrop = true;
            subLabels[2].AutoSize = true;
            subLabels[2].Location = new System.Drawing.Point(points[9, 0], points[9, 1]);
            subLabels[2].Name = "lblDC-DragDrop-" + size;
            subLabels[2].Size = new System.Drawing.Size(sizes[8, 0], sizes[8, 1]);
            subLabels[2].TabIndex = 0;
            subLabels[2].Text = "Drop Here";

            return panel;
        }

        public object SecondaryContainer()
        {
            // Initialisation 

            // Sub-Panels
            subPanels.Add(new Panel());
            subPanels[0].SuspendLayout();

            //TextBoxes
            for(int i = 0; i < 3; i++)
            {
                subTextBoxes.Add(new TextBox());
                subTextBoxes[i].SuspendLayout();

                // Related to Container
                if(i != 0)
                    subPanels[0].Controls.Add(subTextBoxes[i]);
            }

            //Labels
            for(int i = 0; i < 2; i++)
            {
                subLabels.Add(new Label());
                subLabels[i].SuspendLayout();

                // Related to Container
                subPanels[0].Controls.Add(subLabels[i]);
            }
        
            // Main Component
            panel.Controls.Add(subPanels[0]);
            panel.Controls.Add(subTextBoxes[0]);
            panel.Location = new System.Drawing.Point(points[0, 0], points[0, 1]);
            panel.Name = "pnlCS-SubComponent-" + size;
            panel.Size = new System.Drawing.Size(sizes[0, 0], sizes[0, 1]);
            panel.TabIndex = 2;

            // Panel: Container - 0
            subPanels[0].BorderStyle = BorderStyle.FixedSingle;
            subPanels[1].Location = new System.Drawing.Point(points[1,0], points[1,1]);
            subPanels[2].Name = "pnlCS-Container-" + size;
            subPanels[3].Size = new System.Drawing.Size(sizes[1, 0], sizes[1, 1]);
            subPanels[4].TabIndex = 1;

            // TextBox: Name - 0
            subTextBoxes[0].ForeColor = System.Drawing.SystemColors.ControlDark;
            subTextBoxes[0].Location = new System.Drawing.Point(points[6, 0], points[6, 1]);
            subTextBoxes[0].Name = "tbCS-Name-" + size;
            subTextBoxes[0].Size = new System.Drawing.Size(sizes[5, 0], sizes[5, 1]);
            subTextBoxes[0].TabIndex = 0;
            subTextBoxes[0].Name = tool + " Name";

            // TextBox: DataType - 1
            subTextBoxes[1].Location = new System.Drawing.Point(points[2, 0], points[2, 1]);
            subTextBoxes[1].Name = "tbCS-DataType-" + size;
            subTextBoxes[1].Size = new System.Drawing.Size(sizes[2, 0], sizes[2, 1]);
            subTextBoxes[1].TabIndex = 2;

            // TextBox: Member - 2
            subTextBoxes[2].Location = new System.Drawing.Point(points[3, 0], points[3, 1]);
            subTextBoxes[2].Name = "tbCS-Member-" + size;
            subTextBoxes[2].Size = new System.Drawing.Size(sizes[2, 0], sizes[2, 1]);
            subTextBoxes[2].TabIndex = 2;

            // Label: DataType - 0
            subLabels[0].AutoSize = true;
            subLabels[0].Location = new System.Drawing.Point(points[4, 0], points[4, 1]);
            subLabels[0].Name = "lblCS-DataType-" + size;
            subLabels[0].Size = new System.Drawing.Size(sizes[3, 0], sizes[3, 1]);
            subLabels[0].TabIndex = 1;
            subLabels[0].Text = "Data-Type:";

            // Label: Member - 1
            subLabels[1].AutoSize = true;
            subLabels[1].Location = new System.Drawing.Point(points[5, 0], points[5, 1]);
            subLabels[1].Name = "lblCS-Member-" + size;
            subLabels[1].Size = new System.Drawing.Size(sizes[4, 0], sizes[4, 1]);
            subLabels[1].TabIndex = 0;
            subLabels[1].Text = "Member:";

            return panel;
        }

        public object ChildContainer()
        {
            int[] newOrigin = LocSize.PointGenerator(type, size);

            for (int i = 0; i < 3; i++)
            {
                subTextBoxes.Add(new TextBox());
                subTextBoxes[i].SuspendLayout();

                // Commons:

                panel.Controls.Add(subTextBoxes[i]);

                subTextBoxes[i].ForeColor = System.Drawing.SystemColors.ControlDark;
                subTextBoxes[i].Size = new System.Drawing.Size(sizes[1, 0], sizes[1, 0]);
                subTextBoxes[i].TextAlign = HorizontalAlignment.Center;
            }

            // Main Component
            panel.BorderStyle = BorderStyle.FixedSingle;
            panel.Location = new System.Drawing.Point(points[0, 0] + newOrigin[0], points[0, 1] + newOrigin[1]);
            panel.Name = "pnlCC-SubComponent-" + size;
            panel.Size = new System.Drawing.Size(sizes[0,0], sizes[0,1]);
            panel.TabIndex = 3;

            // Textbox - Name - 0
            
            subTextBoxes[0].Location = new System.Drawing.Point(points[1, 0], points[1, 1]);
            subTextBoxes[0].Name = "tbCC-Name-" + size;
            subTextBoxes[0].TabIndex = 0;
            subTextBoxes[0].Text = tool + " Name";
            subTextBoxes[0].Click += actions.ClearTextBox;

            // Textbox - Member - 1
            subTextBoxes[1].Location = new System.Drawing.Point(points[2, 0], points[2, 1]);
            subTextBoxes[1].Name = "tbCC-Member-" + size;
            subTextBoxes[1].TabIndex = 2;
            subTextBoxes[1].Text = "Member";
            subTextBoxes[1].Click += actions.ClearTextBox;

            // Textbox - DataType - 2
            subTextBoxes[2].Location = new System.Drawing.Point(points[3, 0], points[3, 1]);
            subTextBoxes[2].Name = "tbCC-DataType-" + size;
            subTextBoxes[2].TabIndex = 3;
            subTextBoxes[2].Text = "Data Type";
            subTextBoxes[2].Click += actions.ClearTextBox;

            return panel;
        }
    }

    public static class LocSize
    {
        private static bool bStart = false;
        private static VP_Tools.Cache cacheX, cacheY;

        private static readonly int[,] defaultContainerPoints = new int[12, 2]
        {
            { 3, 3 }, // COMPONENT
            { 4, 30 }, // CONTAINER
            { 85, 27 }, // TEXT BOX: Data-Type
            { 85, 3 }, // TEXT BOX: Member
            { 19, 30 }, // Label: Data-Type
            { 31, 7 }, // Label: Member
            { 4, 4 }, // TEXT BOX: Name
            { 3, 47 }, // Group Box: Children
            { 3, 16 }, // Panel Children
            { 82, 23 }, // Label: Children
            { 151, 3 }, // Button: Properties
            { 218, 3 } // Button: Remove
        };

        private static readonly int[,] defaultContainerSizes = new int[11, 2]
        {
            { 245, 166 }, // COMPONENT
            { 238, 131 }, // CONTAINER
            { 100, 20 }, // TWO TEXT BOXES
            { 60, 13 }, // Label: Data-Type
            { 48, 13 }, // Label: Member
            { 141, 20 }, // TEXT BOX: Name
            { 230, 79 }, // Group Box: Children
            { 224, 60 }, // Panel Children
            { 56, 13 }, // Label: Children
            { 63, 21 }, // Button: Properties
            { 24, 21 } // Button: Remove
        };

        private static readonly int[,] defaultSecondaryPoints = new int[7, 2]
        {
            { 3, 3 }, // COMPONENT
            { 4, 30 }, // CONTAINER
            { 85, 27 }, // TB: DataType
            { 85 , 4 }, // TB: Member
            { 19, 30 }, // Label: Data-Type
            { 31, 7 }, // Label: Member
            { 4, 4 }, // TB: Name
        };

        private static readonly int[,] defaultSecondarySizes = new int[6, 2]
        {
            { 211, 95 }, // COMPONENT
            { 204, 60 }, // CONTAINER
            { 100, 20 }, // TWO TEXT BOXES
            { 60, 13 }, // Label: Data-Type
            { 48, 13 }, // Label: Member
            { 169, 20 }, // TB: Name
        };

        private static readonly int[,] defaultChildPoints = new int[4, 2]
        {
            { 16, -57 }, // COMPONENT
            { 6, 4 }, // Textbox: Name
            { 93, 4 }, // Textbox: Member
            { 49, 30 } // Textbox: DataType
        };

        private static readonly int[,] defaultChildSizes = new int[2, 2]
        {
            { 184, 55 }, // COMPONENT
            { 80, 20 } // Textboxes
        };

        public static int[,] GetPoints(int sel)
        {
            if (sel == 0)
                return defaultContainerPoints;

            if (sel == 1)
                return defaultSecondaryPoints;

            return defaultChildPoints;
        }

        public static int[,] GetSizes(int sel)
        {
            if (sel == 0)
                return defaultContainerSizes;

            if (sel == 1)
                return defaultSecondarySizes;

            return defaultChildSizes;
        }

        public static int[] PointGenerator(int sel, int size, bool bResize = false)
        {
            if (sel == 0)
            {
                int lastSize = (172 * (size - 2));

                if (bStart) lastSize = (172 * (cacheY.Integer - 2));

                if (lastSize == 0) { cacheX = new VP_Tools.Cache() { Integer = 0 }; }

                if (size % 2 == 1) { cacheX = new VP_Tools.Cache() { Integer = lastSize }; }
                if (size % 2 == 0) { cacheY = new VP_Tools.Cache() { Integer = size }; if (cacheY.Integer > 3 && !bStart) bStart = !bStart; }

                if (sel == 0 && !bResize)
                {
                    if (size == 1) return new [] { 126, 147 };

                    // Odd

                    // (172 * size) + 3
                    if (size % 2 == 1) return new [] { 0, lastSize };
                    return new [] { 251, cacheX.Integer };
                }

                return new [] { 0, 0 };
            }
            
            if(sel == 2) return new [] { 0, 60 };

            return null;
        }
    }
}