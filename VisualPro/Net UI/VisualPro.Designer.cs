
namespace VP_UI
{
    partial class VisualPro
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(VisualPro));
            this.splitContainer = new System.Windows.Forms.SplitContainer();
            this.gbTools_SaveOptions = new System.Windows.Forms.GroupBox();
            this.btnSaveCode = new System.Windows.Forms.Button();
            this.bxALanguages = new System.Windows.Forms.ComboBox();
            this.gbTools_Outline = new System.Windows.Forms.GroupBox();
            this.btn_classes = new System.Windows.Forms.Button();
            this.btn_variables = new System.Windows.Forms.Button();
            this.btn_functions = new System.Windows.Forms.Button();
            this.gbWorkArea = new System.Windows.Forms.GroupBox();
            this.pnlWorkArea = new System.Windows.Forms.Panel();
            this.dialog_saveFile = new System.Windows.Forms.SaveFileDialog();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer)).BeginInit();
            this.splitContainer.Panel1.SuspendLayout();
            this.splitContainer.Panel2.SuspendLayout();
            this.splitContainer.SuspendLayout();
            this.gbTools_SaveOptions.SuspendLayout();
            this.gbTools_Outline.SuspendLayout();
            this.gbWorkArea.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer
            // 
            this.splitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer.Location = new System.Drawing.Point(0, 0);
            this.splitContainer.Name = "splitContainer";
            // 
            // splitContainer.Panel1
            // 
            this.splitContainer.Panel1.Controls.Add(this.gbTools_SaveOptions);
            this.splitContainer.Panel1.Controls.Add(this.gbTools_Outline);
            // 
            // splitContainer.Panel2
            // 
            this.splitContainer.Panel2.AccessibleName = "";
            this.splitContainer.Panel2.Controls.Add(this.gbWorkArea);
            this.splitContainer.Size = new System.Drawing.Size(809, 506);
            this.splitContainer.SplitterDistance = 268;
            this.splitContainer.TabIndex = 0;
            // 
            // gbTools_SaveOptions
            // 
            this.gbTools_SaveOptions.Controls.Add(this.btnSaveCode);
            this.gbTools_SaveOptions.Controls.Add(this.bxALanguages);
            this.gbTools_SaveOptions.Location = new System.Drawing.Point(21, 69);
            this.gbTools_SaveOptions.Name = "gbTools_SaveOptions";
            this.gbTools_SaveOptions.Size = new System.Drawing.Size(222, 49);
            this.gbTools_SaveOptions.TabIndex = 4;
            this.gbTools_SaveOptions.TabStop = false;
            this.gbTools_SaveOptions.Text = "Save Options";
            // 
            // btnSaveCode
            // 
            this.btnSaveCode.Location = new System.Drawing.Point(139, 18);
            this.btnSaveCode.Name = "btnSaveCode";
            this.btnSaveCode.Size = new System.Drawing.Size(75, 23);
            this.btnSaveCode.TabIndex = 1;
            this.btnSaveCode.Text = "Save Code";
            this.btnSaveCode.UseVisualStyleBackColor = true;
            this.btnSaveCode.Click += new System.EventHandler(this.btnSaveCode_Click);
            // 
            // bxALanguages
            // 
            this.bxALanguages.FormattingEnabled = true;
            this.bxALanguages.Location = new System.Drawing.Point(6, 19);
            this.bxALanguages.Name = "bxALanguages";
            this.bxALanguages.Size = new System.Drawing.Size(121, 21);
            this.bxALanguages.TabIndex = 0;
            this.bxALanguages.Text = "Select Language...";
            // 
            // gbTools_Outline
            // 
            this.gbTools_Outline.Controls.Add(this.btn_classes);
            this.gbTools_Outline.Controls.Add(this.btn_variables);
            this.gbTools_Outline.Controls.Add(this.btn_functions);
            this.gbTools_Outline.Location = new System.Drawing.Point(21, 12);
            this.gbTools_Outline.Name = "gbTools_Outline";
            this.gbTools_Outline.Size = new System.Drawing.Size(232, 51);
            this.gbTools_Outline.TabIndex = 3;
            this.gbTools_Outline.TabStop = false;
            this.gbTools_Outline.Text = "Outline Tools";
            // 
            // btn_classes
            // 
            this.btn_classes.Location = new System.Drawing.Point(6, 19);
            this.btn_classes.Name = "btn_classes";
            this.btn_classes.Size = new System.Drawing.Size(75, 23);
            this.btn_classes.TabIndex = 0;
            this.btn_classes.Text = "Class";
            this.btn_classes.UseVisualStyleBackColor = true;
            this.btn_classes.MouseDown += new System.Windows.Forms.MouseEventHandler(this.DragStart);
            // 
            // btn_variables
            // 
            this.btn_variables.Location = new System.Drawing.Point(147, 19);
            this.btn_variables.Name = "btn_variables";
            this.btn_variables.Size = new System.Drawing.Size(75, 23);
            this.btn_variables.TabIndex = 2;
            this.btn_variables.Text = "Variable";
            this.btn_variables.UseVisualStyleBackColor = true;
            this.btn_variables.MouseDown += new System.Windows.Forms.MouseEventHandler(this.DragStart);
            // 
            // btn_functions
            // 
            this.btn_functions.Location = new System.Drawing.Point(77, 19);
            this.btn_functions.Name = "btn_functions";
            this.btn_functions.Size = new System.Drawing.Size(75, 23);
            this.btn_functions.TabIndex = 1;
            this.btn_functions.Text = "Function";
            this.btn_functions.UseVisualStyleBackColor = true;
            this.btn_functions.MouseDown += new System.Windows.Forms.MouseEventHandler(this.DragStart);
            // 
            // gbWorkArea
            // 
            this.gbWorkArea.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.gbWorkArea.Controls.Add(this.pnlWorkArea);
            this.gbWorkArea.Location = new System.Drawing.Point(14, 12);
            this.gbWorkArea.Name = "gbWorkArea";
            this.gbWorkArea.Size = new System.Drawing.Size(511, 491);
            this.gbWorkArea.TabIndex = 0;
            this.gbWorkArea.TabStop = false;
            this.gbWorkArea.Text = "Work Area";
            // 
            // pnlWorkArea
            // 
            this.pnlWorkArea.AllowDrop = true;
            this.pnlWorkArea.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pnlWorkArea.AutoScroll = true;
            this.pnlWorkArea.Location = new System.Drawing.Point(3, 16);
            this.pnlWorkArea.Name = "pnlWorkArea";
            this.pnlWorkArea.Size = new System.Drawing.Size(502, 469);
            this.pnlWorkArea.TabIndex = 0;
            this.pnlWorkArea.DragDrop += new System.Windows.Forms.DragEventHandler(this.WorkareaDragEnd);
            this.pnlWorkArea.DragEnter += new System.Windows.Forms.DragEventHandler(this.WorkareaDragEnter);
            // 
            // dialog_saveFile
            // 
            this.dialog_saveFile.DefaultExt = "vp";
            this.dialog_saveFile.Filter = "VisualPro Compilation|*.vp|All Files|*.*";
            // 
            // VisualPro
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(809, 506);
            this.Controls.Add(this.splitContainer);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(825, 545);
            this.MinimumSize = new System.Drawing.Size(825, 545);
            this.Name = "VisualPro";
            this.Text = "VisualPro";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.VisualPro_FormClosing);
            this.splitContainer.Panel1.ResumeLayout(false);
            this.splitContainer.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer)).EndInit();
            this.splitContainer.ResumeLayout(false);
            this.gbTools_SaveOptions.ResumeLayout(false);
            this.gbTools_Outline.ResumeLayout(false);
            this.gbWorkArea.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer;
        private System.Windows.Forms.Button btn_functions;
        private System.Windows.Forms.Button btn_classes;
        private System.Windows.Forms.GroupBox gbTools_Outline;
        private System.Windows.Forms.Button btn_variables;
        private System.Windows.Forms.GroupBox gbWorkArea;
        private System.Windows.Forms.Panel pnlWorkArea;
        private System.Windows.Forms.GroupBox gbTools_SaveOptions;
        private System.Windows.Forms.Button btnSaveCode;
        private System.Windows.Forms.ComboBox bxALanguages;
        private System.Windows.Forms.SaveFileDialog dialog_saveFile;
    }
}

