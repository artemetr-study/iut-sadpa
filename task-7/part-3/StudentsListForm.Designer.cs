namespace study_iut_sadpa_3_semester_task_7_part_3
{
    partial class StudentsListForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.StudentsDataGridView = new System.Windows.Forms.DataGridView();
            this.studentBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.SaveStudentsDatasetToCsvButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.PathTextBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.StudentsDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // StudentsDataGridView
            // 
            this.StudentsDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.StudentsDataGridView.Location = new System.Drawing.Point(13, 13);
            this.StudentsDataGridView.Name = "StudentsDataGridView";
            this.StudentsDataGridView.Size = new System.Drawing.Size(775, 396);
            this.StudentsDataGridView.TabIndex = 0;
            // 
            // studentBindingSource
            // 
            this.studentBindingSource.DataSource = typeof(study_iut_sadpa_3_semester_task_7_part_3.Student);
            // 
            // SaveStudentsDatasetToCsvButton
            // 
            this.SaveStudentsDatasetToCsvButton.Location = new System.Drawing.Point(632, 415);
            this.SaveStudentsDatasetToCsvButton.Name = "SaveStudentsDatasetToCsvButton";
            this.SaveStudentsDatasetToCsvButton.Size = new System.Drawing.Size(75, 23);
            this.SaveStudentsDatasetToCsvButton.TabIndex = 1;
            this.SaveStudentsDatasetToCsvButton.Text = "Save";
            this.SaveStudentsDatasetToCsvButton.UseVisualStyleBackColor = true;
            this.SaveStudentsDatasetToCsvButton.Click += new System.EventHandler(this.SaveStudentsDatasetToCsvButton_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Location = new System.Drawing.Point(713, 415);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(75, 23);
            this.ExitButton.TabIndex = 2;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            // 
            // PathTextBox
            // 
            this.PathTextBox.Location = new System.Drawing.Point(442, 417);
            this.PathTextBox.Name = "PathTextBox";
            this.PathTextBox.Size = new System.Drawing.Size(184, 20);
            this.PathTextBox.TabIndex = 3;
            // 
            // StudentsListForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.PathTextBox);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.SaveStudentsDatasetToCsvButton);
            this.Controls.Add(this.StudentsDataGridView);
            this.Name = "StudentsListForm";
            this.Text = "StudentsList";
            this.Load += new System.EventHandler(this.StudentsListForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.StudentsDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.studentBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView StudentsDataGridView;
        private System.Windows.Forms.BindingSource studentBindingSource;
        private System.Windows.Forms.Button SaveStudentsDatasetToCsvButton;
        private System.Windows.Forms.Button ExitButton;
        private System.Windows.Forms.TextBox PathTextBox;
    }
}

