using CsvHelper;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace study_iut_sadpa_3_semester_task_7_part_3
{
    public partial class StudentsListForm : Form
    {
        private string PathToCsvFile { get; set; }

        private bool IsStudentsDatasetSave { get; set; } = false;

        public StudentsListForm(string pathToCsvFile)
        {
            this.PathToCsvFile = pathToCsvFile;
            InitializeComponent();
        }

        private void SaveStudentsDatasetToCsvButton_Click(object sender, EventArgs e)
        {
            using(SaveFileDialog saveFileDialog = new SaveFileDialog() { Filter = "CSV Files (*.csv)|*.csv", ValidateNames = true })
            {
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    using (StreamWriter streamWriter = new StreamWriter(saveFileDialog.FileName))
                    {
                        using (CsvWriter csvWriter = new CsvWriter(streamWriter, CultureInfo.InvariantCulture))
                        {
                            csvWriter.Configuration.Delimiter = ";";
                            csvWriter.WriteRecords(studentBindingSource.DataSource as List<Student>);
                            //MessageBox.Show("Students data has been saved!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        }
                    }
                }
            }
        }

        private void StudentsListForm_Load(object sender, EventArgs e)
        {
            DataTable dt = new DataTable();
            File.ReadLines(this.PathToCsvFile).Take(1)
                .SelectMany(x => x.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries))
                .ToList()
                .ForEach(x => dt.Columns.Add(x.Trim()));

            File.ReadLines(this.PathToCsvFile).Skip(1)
                .Select(x => x.Split(';'))
                .ToList()
                .ForEach(line => dt.Rows.Add(line));

            StudentsDataGridView.DataSource = dt;
        }

        private static List<Student> LoadStudentsDataset(string pathToCsvFile)
        {
            List<Student> result = null;
            using (StreamReader streamReader = new StreamReader(pathToCsvFile))
            {
                using (CsvReader csvReader = new CsvReader(streamReader, CultureInfo.InvariantCulture))
                {
                    csvReader.Configuration.Delimiter = ";";
                    result = csvReader.GetRecords<Student>().ToList<Student>();
                }
            }
            return result;
        }
    }
}
