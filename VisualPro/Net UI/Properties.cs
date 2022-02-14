using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;

namespace VP_UI
{
    public partial class Property : Form
    {
        public Property()
        {
            InitializeComponent();

            // Reference https://docs.microsoft.com/en-us/dotnet/api/system.windows.forms.propertygrid?view=windowsdesktop-6.0
            Properties.PropertyList_MT pl = new Properties.PropertyList_MT();
            propertyGrid1.SelectedObject = pl;
        }
    }
}

namespace VP_UI.Properties
{
    public class PropertyList_AT
    {

        private string argDTs, argName;

        [Browsable(true)]
        [ReadOnly(false)]
        [Description("Edit Argument's data-type.")]
        [Category("Function Details")]
        [DisplayName("Data-Type:")]
        public string Property_ArgDTs { get { return argDTs; } set { argDTs = value; } }

        [Browsable(true)]
        [ReadOnly(false)]
        [Description("Edit Argument's name.")]
        [Category("Function Details")]
        [DisplayName("Name:")]
        public string Property_ArgName { get { return argName; } set { argName = value; } }
    }

    public class PropertyList_MT
    {
        private List<PropertyList_AT> argList = new List<PropertyList_AT>();

        [Browsable(true)]
        [ReadOnly(false)]
        [Description("Add or remove arguments.")]
        [Category("Function Arguments")]
        [DisplayName("Add or Remove Arguments")]
        public List<PropertyList_AT> Property_ArgList
        { get { return argList; } set { argList = value; } }
    }
}