using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace study_iut_sadpa_3_semester_task_7_part_3
{
    public class CsvParser
    {
        private string PathToFile { get; set; }
        private string Delimiter { get; set; }

        public CsvParser(string pathToFile, string delimiter = ";")
        {
            this.PathToFile = pathToFile;
            this.Delimiter = delimiter;
        }

        public void WriteListToFile(List<List<string>> data)
        {
            string formatedData = CsvParser.ListToCsvString(data, this.Delimiter);

            using (StreamWriter streamWriter = new StreamWriter(this.PathToFile))
            {
                streamWriter.Write(formatedData);
            }
        }

        public List<List<string>> ReadListFromFile()
        {
            List<List<string>> result = null;

            using (StreamReader streamReader = new StreamReader(this.PathToFile))
            {
                string line;

                while ((line = streamReader.ReadLine()) != null)
                {
                    result.Add(CsvParser.StringToList(line, this.Delimiter.ToCharArray()[0]));
                }
            }

            return result;
        }

        private static List<string> StringToList(string data, char delimiter = ';')
        {
            return data.Split(new char[] { delimiter }).ToList();
        }

        private static string ListToCsvString(List<string> data, string delimiter = ";")
        {
            return string.Join(delimiter, data.ToArray());
        }

        private static string ListToCsvString(List<List<string>> data, string delimiter = ";")
        {
            List<string> result = null;
            foreach (List<string> subData in data)
            {
                result.Add(CsvParser.ListToCsvString(subData, delimiter));
            }

            return string.Join("\n", result.ToArray());
        }
    }
}