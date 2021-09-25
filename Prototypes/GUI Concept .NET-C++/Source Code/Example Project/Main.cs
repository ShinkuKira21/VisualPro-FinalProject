using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Example_Project
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        // C++ Communication - Example 1
        private void btnDLLE1_Click(object sender, EventArgs e)
        {
            // Calls Helloworld and converts IntPtr (C++ Const Char*) to a String (Method: Ansi)
            lblDLLE1_1.Text = Marshal.PtrToStringAnsi(DLL_Manager.Helloworld());
            lblDLLE1_2.Text = "C# says Helloworld";
            btnDLLE1.Enabled = false; // disable button
        }

        private void resetBox(object sender, EventArgs e)
        { if(((TextBox)sender).Text == "Num Only") ((TextBox) sender).Text = ""; }

        private void btnDLLE2_Click(object sender, EventArgs e)
        {
            if (tbDLLE2_1.Text != "Num Only" && tbDLLE2_2.Text != "Num Only" && tbDLLE2_1.Text != "" && tbDLLE2_2.Text != "")
            {
                double x = Double.Parse(tbDLLE2_1.Text), y = Double.Parse(tbDLLE2_2.Text);
                lblDLLE2_4.Text = Convert.ToString(DLL_Manager.Calculator(x, y, rbDLLE2_1.Checked));

                double result;
                if (rbDLLE2_1.Checked)
                    result = x + y;

                else result = x - y;

                lblDLLE2_6.Text = Convert.ToString(result);
            }

        }
    }
}
