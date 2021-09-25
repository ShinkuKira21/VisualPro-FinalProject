
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
            this.SuspendLayout();
            // 
            // btnDLLE1
            // 
            this.btnDLLE1.Location = new System.Drawing.Point(31, 55);
            this.btnDLLE1.Name = "btnDLLE1";
            this.btnDLLE1.Size = new System.Drawing.Size(75, 44);
            this.btnDLLE1.TabIndex = 0;
            this.btnDLLE1.Text = "DLL Example 1";
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
            this.btnDLLE2.Location = new System.Drawing.Point(251, 81);
            this.btnDLLE2.Name = "btnDLLE2";
            this.btnDLLE2.Size = new System.Drawing.Size(75, 44);
            this.btnDLLE2.TabIndex = 3;
            this.btnDLLE2.Text = "DLL Example 2";
            this.btnDLLE2.UseVisualStyleBackColor = true;
            this.btnDLLE2.Click += new System.EventHandler(this.btnDLLE2_Click);
            // 
            // tbDLLE2_1
            // 
            this.tbDLLE2_1.Location = new System.Drawing.Point(269, 5);
            this.tbDLLE2_1.Name = "tbDLLE2_1";
            this.tbDLLE2_1.Size = new System.Drawing.Size(57, 20);
            this.tbDLLE2_1.TabIndex = 4;
            this.tbDLLE2_1.Text = "Num Only";
            this.tbDLLE2_1.Click += new System.EventHandler(this.resetBox);
            // 
            // tbDLLE2_2
            // 
            this.tbDLLE2_2.Location = new System.Drawing.Point(269, 30);
            this.tbDLLE2_2.Name = "tbDLLE2_2";
            this.tbDLLE2_2.Size = new System.Drawing.Size(57, 20);
            this.tbDLLE2_2.TabIndex = 5;
            this.tbDLLE2_2.Text = "Num Only";
            this.tbDLLE2_2.Click += new System.EventHandler(this.resetBox);
            // 
            // lblDLLE2_1
            // 
            this.lblDLLE2_1.AutoSize = true;
            this.lblDLLE2_1.Location = new System.Drawing.Point(248, 8);
            this.lblDLLE2_1.Name = "lblDLLE2_1";
            this.lblDLLE2_1.Size = new System.Drawing.Size(15, 13);
            this.lblDLLE2_1.TabIndex = 7;
            this.lblDLLE2_1.Text = "x:";
            // 
            // lblDLLE2_2
            // 
            this.lblDLLE2_2.AutoSize = true;
            this.lblDLLE2_2.Location = new System.Drawing.Point(248, 33);
            this.lblDLLE2_2.Name = "lblDLLE2_2";
            this.lblDLLE2_2.Size = new System.Drawing.Size(15, 13);
            this.lblDLLE2_2.TabIndex = 8;
            this.lblDLLE2_2.Text = "y:";
            // 
            // rbDLLE2_1
            // 
            this.rbDLLE2_1.AutoSize = true;
            this.rbDLLE2_1.Checked = true;
            this.rbDLLE2_1.Location = new System.Drawing.Point(342, 8);
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
            this.rbDLLE2_2.Location = new System.Drawing.Point(342, 33);
            this.rbDLLE2_2.Name = "rbDLLE2_2";
            this.rbDLLE2_2.Size = new System.Drawing.Size(65, 17);
            this.rbDLLE2_2.TabIndex = 10;
            this.rbDLLE2_2.Text = "Subtract";
            this.rbDLLE2_2.UseVisualStyleBackColor = true;
            // 
            // lblDLLE2_3
            // 
            this.lblDLLE2_3.AutoSize = true;
            this.lblDLLE2_3.Location = new System.Drawing.Point(248, 53);
            this.lblDLLE2_3.Name = "lblDLLE2_3";
            this.lblDLLE2_3.Size = new System.Drawing.Size(62, 13);
            this.lblDLLE2_3.TabIndex = 11;
            this.lblDLLE2_3.Text = "C++ Result:";
            // 
            // lblDLLE2_4
            // 
            this.lblDLLE2_4.AutoSize = true;
            this.lblDLLE2_4.Location = new System.Drawing.Point(311, 53);
            this.lblDLLE2_4.Name = "lblDLLE2_4";
            this.lblDLLE2_4.Size = new System.Drawing.Size(13, 13);
            this.lblDLLE2_4.TabIndex = 12;
            this.lblDLLE2_4.Text = "0";
            // 
            // lblDLLE2_6
            // 
            this.lblDLLE2_6.AutoSize = true;
            this.lblDLLE2_6.Location = new System.Drawing.Point(311, 66);
            this.lblDLLE2_6.Name = "lblDLLE2_6";
            this.lblDLLE2_6.Size = new System.Drawing.Size(13, 13);
            this.lblDLLE2_6.TabIndex = 14;
            this.lblDLLE2_6.Text = "0";
            // 
            // lblDLLE2_5
            // 
            this.lblDLLE2_5.AutoSize = true;
            this.lblDLLE2_5.Location = new System.Drawing.Point(248, 66);
            this.lblDLLE2_5.Name = "lblDLLE2_5";
            this.lblDLLE2_5.Size = new System.Drawing.Size(57, 13);
            this.lblDLLE2_5.TabIndex = 13;
            this.lblDLLE2_5.Text = "C# Result:";
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(417, 137);
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
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Main";
            this.Text = "Main Application";
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
    }
}

