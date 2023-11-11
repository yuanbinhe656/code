using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验一
{
    public partial class Form1 : System.Windows.Forms.Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
           DialogResult a= MessageBox.Show("请确认是否关闭","确认对话框",MessageBoxButtons.YesNo);
            if (a==DialogResult.No)
            {
                e.Cancel = true;
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 a = new Form2();
            a.ShowDialog();
         
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 a = new Form3();
            a.Show();
        }

        
     
    }
}
