using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace study_iut_sadpa_3_semester_task_7_part_3
{
    public class Student
    {
        public int Id { get; set; }

        public int GroupId { get; set; }

        public string LastName { get; set; }

        public string FirstName { get; set; }

        public string SecondName { get; set; }

        public int[] Marks { get; set; }
    }
}
