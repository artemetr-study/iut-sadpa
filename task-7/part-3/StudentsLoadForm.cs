using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace study_iut_sadpa_3_semester_task_7_part_3
{
    public partial class StudentsLoadForm : Form
    {
        public StudentsLoadForm()
        {
            InitializeComponent();
        }

        private void OpenButton_Click(object sender, EventArgs e)
        {
            StudentsListForm a = new StudentsListForm(PathTextBox.Text);
            a.Show();
        }

        private void ChangeFileButton_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.Filter = "CSV Files (*.csv)|*.csv";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {                
                    PathTextBox.Text = openFileDialog.FileName;             
                }
            }
        }
    }
}
