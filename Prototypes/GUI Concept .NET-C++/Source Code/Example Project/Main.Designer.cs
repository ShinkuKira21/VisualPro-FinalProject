
namespace Example_Project
{
    partial class Main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnDLLE1 = new System.Windows.Forms.Button();
            this.lblDLLE1_1 = new System.Windows.Forms.Label();
            this.lblDLLE1_2 = new System.Windows.Forms.Label();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.btnDLLE2 = new System.Windows.Forms.Button();
            this.tbDLLE2_1 = new System.Windows.Forms.TextBox();
            this.tbDLLE2_2 = new System.Windows.Forms.TextBox();
            this.lblDLLE2_1 = new System.Windows.Forms.Label();
            this.lblDLLE2_2 = new System.Windows.Forms.Label();
            this.rbDLLE2_1 = new System.Windows.Forms.RadioButton();
            this.rbDLLE2_2 = new System.Windows.Forms.RadioButton();
            this.lblDLLE2_3 = new System.Windows.Forms.Label();
            this.lblDLLE2_4 = new System.Windows.Forms.Label();
            this.lblDLLE2_6 = new System.Windows.Forms.Label();
            this.lblDLLE2_5 = new System.Windows.Forms.Label();
            this.grpBox_e1 = new System.Windows.Forms.GroupBox();
            this.grpBox_E2 = new System.Windows.Forms.GroupBox();
            this.grpBox_E3 = new System.Windows.Forms.GroupBox();
            this.pcBox_E3 = new System.Windows.Forms.PictureBox();
            this.richTB_E3 = new System.Windows.Forms.RichTextBox();
            this.grpBox_E3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pcBox_E3)).BeginInit();
            this.SuspendLayout();
            // 
            // btnDLLE1
            // 
            this.btnDLLE1.Location = new System.Drawing.Point(31, 55);
            this.btnDLLE1.Name = "btnDLLE1";
            this.btnDLLE1.Size = new System.Drawing.Size(75, 44);
            this.btnDLLE1.TabIndex = 0;
            this.btnDLLE1.Text = "Run";
            this.btnDLLE1.UseVisualStyleBackColor = true;
            this.btnDLLE1.Click += new System.EventHandler(this.btnDLLE1_Click);
            // 
            // lblDLLE1_1
            // 
            this.lblDLLE1_1.AutoSize = true;
            this.lblDLLE1_1.Location = new System.Drawing.Point(22, 17);
            this.lblDLLE1_1.Name = "lblDLLE1_1";
            this.lblDLLE1_1.Size = new System.Drawing.Size(26, 13);
            this.lblDLLE1_1.TabIndex = 1;
            this.lblDLLE1_1.Text = "C++";
            this.lblDLLE1_1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblDLLE1_2
            // 
            this.lblDLLE1_2.AutoSize = true;
            this.lblDLLE1_2.Location = new System.Drawing.Point(23, 36);
            this.lblDLLE1_2.Name = "lblDLLE1_2";
            this.lblDLLE1_2.Size = new System.Drawing.Size(21, 13);
            this.lblDLLE1_2.TabIndex = 2;
            this.lblDLLE1_2.Text = "C#";
            // 
            // btnDLLE2
            // 
            this.btnDLLE2.Location = new System.Drawing.Point(33, 199);
            this.btnDLLE2.Name = "btnDLLE2";
            this.btnDLLE2.Size = new System.Drawing.Size(75, 44);
            this.btnDLLE2.TabIndex = 3;
            this.btnDLLE2.Text = "DLL Example 2";
            this.btnDLLE2.UseVisualStyleBackColor = true;
            this.btnDLLE2.Click += new System.EventHandler(this.btnDLLE2_Click);
            // 
            // tbDLLE2_1
            // 
            this.tbDLLE2_1.Location = new System.Drawing.Point(51, 123);
            this.tbDLLE2_1.Name = "tbDLLE2_1";
            this.tbDLLE2_1.Size = new System.Drawing.Size(57, 20);
            this.tbDLLE2_1.TabIndex = 4;
            this.tbDLLE2_1.Text = "Num Only";
            this.tbDLLE2_1.Click += new System.EventHandler(this.resetBox);
            // 
            // tbDLLE2_2
            // 
            this.tbDLLE2_2.Location = new System.Drawing.Point(51, 148);
            this.tbDLLE2_2.Name = "tbDLLE2_2";
            this.tbDLLE2_2.Size = new System.Drawing.Size(57, 20);
            this.tbDLLE2_2.TabIndex = 5;
            this.tbDLLE2_2.Text = "Num Only";
            this.tbDLLE2_2.Click += new System.EventHandler(this.resetBox);
            // 
            // lblDLLE2_1
            // 
            this.lblDLLE2_1.AutoSize = true;
            this.lblDLLE2_1.Location = new System.Drawing.Point(30, 126);
            this.lblDLLE2_1.Name = "lblDLLE2_1";
            this.lblDLLE2_1.Size = new System.Drawing.Size(15, 13);
            this.lblDLLE2_1.TabIndex = 7;
            this.lblDLLE2_1.Text = "x:";
            // 
            // lblDLLE2_2
            // 
            this.lblDLLE2_2.AutoSize = true;
            this.lblDLLE2_2.Location = new System.Drawing.Point(30, 151);
            this.lblDLLE2_2.Name = "lblDLLE2_2";
            this.lblDLLE2_2.Size = new System.Drawing.Size(15, 13);
            this.lblDLLE2_2.TabIndex = 8;
            this.lblDLLE2_2.Text = "y:";
            // 
            // rbDLLE2_1
            // 
            this.rbDLLE2_1.AutoSize = true;
            this.rbDLLE2_1.Checked = true;
            this.rbDLLE2_1.Location = new System.Drawing.Point(123, 126);
            this.rbDLLE2_1.Name = "rbDLLE2_1";
            this.rbDLLE2_1.Size = new System.Drawing.Size(44, 17);
            this.rbDLLE2_1.TabIndex = 9;
            this.rbDLLE2_1.TabStop = true;
            this.rbDLLE2_1.Text = "Add";
            this.rbDLLE2_1.UseVisualStyleBackColor = true;
            // 
            // rbDLLE2_2
            // 
            this.rbDLLE2_2.AutoSize = true;
            this.rbDLLE2_2.Location = new System.Drawing.Point(123, 151);
            this.rbDLLE2_2.Name = "rbDLLE2_2";
            this.rbDLLE2_2.Size = new System.Drawing.Size(65, 17);
            this.rbDLLE2_2.TabIndex = 10;
            this.rbDLLE2_2.Text = "Subtract";
            this.rbDLLE2_2.UseVisualStyleBackColor = true;
            // 
            // lblDLLE2_3
            // 
            this.lblDLLE2_3.AutoSize = true;
            this.lblDLLE2_3.Location = new System.Drawing.Point(30, 171);
            this.lblDLLE2_3.Name = "lblDLLE2_3";
            this.lblDLLE2_3.Size = new System.Drawing.Size(62, 13);
            this.lblDLLE2_3.TabIndex = 11;
            this.lblDLLE2_3.Text = "C++ Result:";
            // 
            // lblDLLE2_4
            // 
            this.lblDLLE2_4.AutoSize = true;
            this.lblDLLE2_4.Location = new System.Drawing.Point(93, 171);
            this.lblDLLE2_4.Name = "lblDLLE2_4";
            this.lblDLLE2_4.Size = new System.Drawing.Size(13, 13);
            this.lblDLLE2_4.TabIndex = 12;
            this.lblDLLE2_4.Text = "0";
            // 
            // lblDLLE2_6
            // 
            this.lblDLLE2_6.AutoSize = true;
            this.lblDLLE2_6.Location = new System.Drawing.Point(93, 184);
            this.lblDLLE2_6.Name = "lblDLLE2_6";
            this.lblDLLE2_6.Size = new System.Drawing.Size(13, 13);
            this.lblDLLE2_6.TabIndex = 14;
            this.lblDLLE2_6.Text = "0";
            // 
            // lblDLLE2_5
            // 
            this.lblDLLE2_5.AutoSize = true;
            this.lblDLLE2_5.Location = new System.Drawing.Point(30, 184);
            this.lblDLLE2_5.Name = "lblDLLE2_5";
            this.lblDLLE2_5.Size = new System.Drawing.Size(57, 13);
            this.lblDLLE2_5.TabIndex = 13;
            this.lblDLLE2_5.Text = "C# Result:";
            // 
            // grpBox_e1
            // 
            this.grpBox_e1.Location = new System.Drawing.Point(13, 3);
            this.grpBox_e1.Name = "grpBox_e1";
            this.grpBox_e1.Size = new System.Drawing.Size(173, 102);
            this.grpBox_e1.TabIndex = 15;
            this.grpBox_e1.TabStop = false;
            this.grpBox_e1.Text = "DLL C Example 1";
            // 
            // grpBox_E2
            // 
            this.grpBox_E2.Location = new System.Drawing.Point(13, 106);
            this.grpBox_E2.Name = "grpBox_E2";
            this.grpBox_E2.Size = new System.Drawing.Size(176, 146);
            this.grpBox_E2.TabIndex = 16;
            this.grpBox_E2.TabStop = false;
            this.grpBox_E2.Text = "DLL C Example 1";
            // 
            // grpBox_E3
            // 
            this.grpBox_E3.Controls.Add(this.pcBox_E3);
            this.grpBox_E3.Controls.Add(this.richTB_E3);
            this.grpBox_E3.Location = new System.Drawing.Point(193, 3);
            this.grpBox_E3.Name = "grpBox_E3";
            this.grpBox_E3.Size = new System.Drawing.Size(238, 249);
            this.grpBox_E3.TabIndex = 17;
            this.grpBox_E3.TabStop = false;
            this.grpBox_E3.Text = "DLL C++ Example 1";
            // 
            // pcBox_E3
            // 
            this.pcBox_E3.BackgroundImage = global::Example_Project.Properties.Resources.off;
            this.pcBox_E3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pcBox_E3.Location = new System.Drawing.Point(16, 120);
            this.pcBox_E3.Name = "pcBox_E3";
            this.pcBox_E3.Size = new System.Drawing.Size(216, 129);
            this.pcBox_E3.TabIndex = 1;
            this.pcBox_E3.TabStop = false;
            this.pcBox_E3.Click += new System.EventHandler(this.pcBox_E3_Click);
            this.pcBox_E3.MouseLeave += new System.EventHandler(this.pcBox_E3_MouseLeave);
            this.pcBox_E3.MouseHover += new System.EventHandler(this.pcBox_E3_MouseHover);
            // 
            // richTB_E3
            // 
            this.richTB_E3.Location = new System.Drawing.Point(16, 19);
            this.richTB_E3.Name = "richTB_E3";
            this.richTB_E3.ReadOnly = true;
            this.richTB_E3.Size = new System.Drawing.Size(216, 96);
            this.richTB_E3.TabIndex = 0;
            this.richTB_E3.Text = "Car Status";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(434, 259);
            this.Controls.Add(this.grpBox_E3);
            this.Controls.Add(this.lblDLLE2_6);
            this.Controls.Add(this.lblDLLE2_5);
            this.Controls.Add(this.lblDLLE2_4);
            this.Controls.Add(this.lblDLLE2_3);
            this.Controls.Add(this.rbDLLE2_2);
            this.Controls.Add(this.rbDLLE2_1);
            this.Controls.Add(this.lblDLLE2_2);
            this.Controls.Add(this.lblDLLE2_1);
            this.Controls.Add(this.tbDLLE2_2);
            this.Controls.Add(this.tbDLLE2_1);
            this.Controls.Add(this.btnDLLE2);
            this.Controls.Add(this.lblDLLE1_2);
            this.Controls.Add(this.lblDLLE1_1);
            this.Controls.Add(this.btnDLLE1);
            this.Controls.Add(this.grpBox_e1);
            this.Controls.Add(this.grpBox_E2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.HelpButton = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Main";
            this.Text = "Main Application";
            this.HelpButtonClicked += new System.ComponentModel.CancelEventHandler(this.Main_HelpButtonClicked);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Main_FormClosing);
            this.grpBox_E3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pcBox_E3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnDLLE1;
        private System.Windows.Forms.Label lblDLLE1_1;
        private System.Windows.Forms.Label lblDLLE1_2;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Button btnDLLE2;
        private System.Windows.Forms.TextBox tbDLLE2_1;
        private System.Windows.Forms.TextBox tbDLLE2_2;
        private System.Windows.Forms.Label lblDLLE2_1;
        private System.Windows.Forms.Label lblDLLE2_2;
        private System.Windows.Forms.RadioButton rbDLLE2_1;
        private System.Windows.Forms.RadioButton rbDLLE2_2;
        private System.Windows.Forms.Label lblDLLE2_3;
        private System.Windows.Forms.Label lblDLLE2_4;
        private System.Windows.Forms.Label lblDLLE2_6;
        private System.Windows.Forms.Label lblDLLE2_5;
        private System.Windows.Forms.GroupBox grpBox_e1;
        private System.Windows.Forms.GroupBox grpBox_E2;
        private System.Windows.Forms.GroupBox grpBox_E3;
        private System.Windows.Forms.PictureBox pcBox_E3;
        private System.Windows.Forms.RichTextBox richTB_E3;
    }
}

