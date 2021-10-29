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
        private Car csCar;
        private IntPtr cppCar;
        private int lastActive;

        public Main()
        {
            InitializeComponent();
            lastActive = 0;
            csCar = new Car("Nissan", "Micra", "NMIC826715212-091");
            cppCar = DLL_Manager.InitialiseCar("Mercedes Benz", "C140", "MB-C140-98261");
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

        private void pcBox_E3_MouseHover(object sender, EventArgs e)
        {
            if (lastActive.Equals(0))
            {
                lastActive = 1;
                this.pcBox_E3.BackgroundImage = Properties.Resources.ac;

                richTB_E3.Text = "C++\n";
                IntPtr cPointer = DLL_Manager.Ignition(cppCar, lastActive);
                ;
                richTB_E3.Text += Marshal.PtrToStringAnsi(cPointer);
                DLL_Manager.DeleteCPointer(cPointer);

                richTB_E3.Text += "\nC#\n";
                richTB_E3.Text += csCar.ModeSelecter(lastActive);
            }
        }

        private void pcBox_E3_MouseLeave(object sender, EventArgs e)
        {
            if (lastActive.Equals(1))
            {
                lastActive = 0;
                this.pcBox_E3.BackgroundImage = Properties.Resources.off;

                richTB_E3.Text = "C++\n";
                IntPtr cPointer = DLL_Manager.Ignition(cppCar, lastActive);
                richTB_E3.Text += Marshal.PtrToStringAnsi(cPointer);
                DLL_Manager.DeleteCPointer(cPointer);

                richTB_E3.Text += "\nC#\n";
                richTB_E3.Text += csCar.ModeSelecter(lastActive);
            }
        }

        private void pcBox_E3_Click(object sender, EventArgs e)
        {
            if (!lastActive.Equals(2))
            {
                lastActive = 2;
                this.pcBox_E3.BackgroundImage = Properties.Resources.ignition;
            }
            
            else
            {
                lastActive = 0;
                this.pcBox_E3.BackgroundImage = Properties.Resources.off;
            }

            richTB_E3.Text = "C++\n";
            IntPtr cPointer = DLL_Manager.Ignition(cppCar, lastActive);
            richTB_E3.Text += Marshal.PtrToStringAnsi(cPointer);
            DLL_Manager.DeleteCPointer(cPointer);

            richTB_E3.Text += "\nC#\n";
            richTB_E3.Text += csCar.ModeSelecter(lastActive);
        }

        private void Main_FormClosing(object sender, FormClosingEventArgs e)
        {
            DLL_Manager.DisposeCar(cppCar);
        }

        private void grpBox_E3_Enter(object sender, EventArgs e)
        {

        }
    }
}
