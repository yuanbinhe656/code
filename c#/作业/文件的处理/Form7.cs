using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace 文件的处理
{
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowDialog();
            richTextBox1.SelectionFont = fontDialog1.Font;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            DialogResult dr = openFileDialog1.ShowDialog();
            if (dr == DialogResult.OK)
            {
                string path = openFileDialog1.FileName;
                FileStream fd = new FileStream(path, FileMode.Open, FileAccess.Read);
                byte[] mo = new byte[fd.Length];
                fd.Read(mo, 0,mo.Length);
                richTextBox1.Text = Encoding.Default.GetString(mo);
                fd.Close();
            }
       
               


        }

        private void button2_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            richTextBox1.SelectionColor = colorDialog1.Color;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            DialogResult sr = saveFileDialog1.ShowDialog();
            if(sr==DialogResult.OK)
            {
                string na = saveFileDialog1.FileName;
                FileStream sa = new FileStream(na, FileMode.Create);
                string stext = richTextBox1.Text;
                byte[] btext = Encoding.Default.GetBytes(stext);
                sa.Write(btext, 0, btext.Length);
                sa.Close();
            }
        }
    }
}
