namespace study_iut_sadpa_3_semester_task_7_part_3
{
    partial class StudentsLoadForm
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
            this.OpenButton = new System.Windows.Forms.Button();
            this.ChangeFileButton = new System.Windows.Forms.Button();
            this.PathTextBox = new System.Windows.Forms.TextBox();
            this.DescriptionLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // OpenButton
            // 
            this.OpenButton.Location = new System.Drawing.Point(12, 59);
            this.OpenButton.Name = "OpenButton";
            this.OpenButton.Size = new System.Drawing.Size(291, 23);
            this.OpenButton.TabIndex = 0;
            this.OpenButton.Text = "Open";
            this.OpenButton.UseVisualStyleBackColor = true;
            this.OpenButton.Click += new System.EventHandler(this.OpenButton_Click);
            // 
            // ChangeFileButton
            // 
            this.ChangeFileButton.Location = new System.Drawing.Point(228, 28);
            this.ChangeFileButton.Name = "ChangeFileButton";
            this.ChangeFileButton.Size = new System.Drawing.Size(75, 23);
            this.ChangeFileButton.TabIndex = 1;
            this.ChangeFileButton.Text = "Change...";
            this.ChangeFileButton.UseVisualStyleBackColor = true;
            this.ChangeFileButton.Click += new System.EventHandler(this.ChangeFileButton_Click);
            // 
            // PathTextBox
            // 
            this.PathTextBox.Location = new System.Drawing.Point(12, 30);
            this.PathTextBox.Name = "PathTextBox";
            this.PathTextBox.Size = new System.Drawing.Size(210, 20);
            this.PathTextBox.TabIndex = 2;
            // 
            // DescriptionLabel
            // 
            this.DescriptionLabel.AutoSize = true;
            this.DescriptionLabel.Location = new System.Drawing.Point(9, 9);
            this.DescriptionLabel.Name = "DescriptionLabel";
            this.DescriptionLabel.Size = new System.Drawing.Size(181, 13);
            this.DescriptionLabel.TabIndex = 3;
            this.DescriptionLabel.Text = "Please select *.csv students dataset.";
            // 
            // StudentsLoadForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(315, 92);
            this.Controls.Add(this.DescriptionLabel);
            this.Controls.Add(this.PathTextBox);
            this.Controls.Add(this.ChangeFileButton);
            this.Controls.Add(this.OpenButton);
            this.Name = "StudentsLoadForm";
            this.Text = "StudentsLoadForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button OpenButton;
        private System.Windows.Forms.Button ChangeFileButton;
        private System.Windows.Forms.TextBox PathTextBox;
        private System.Windows.Forms.Label DescriptionLabel;
    }
}