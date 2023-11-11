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

namespace 实验
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void Form6_Load(object sender, EventArgs e)
        {

        }
        public string[] path = new string[] {  @"E:/文本/texi11.txt",@"E:/文本/texi12.txt" , @"E:/文本/texi13.txt" , @"E:/文本/texi13.txt" , @"E:/文本/texi14.txt" , @"E:/文本/texi15.txt" , @"E:/文本/texi16.txt" };
        private void button1_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[0], FileMode.Create, FileAccess.Write);
            string stext = textBox1.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
           fs.Write(btext, 0, btext.Length);
            
            fs.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            File.Delete(path[0]);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
          
        }

        private void button3_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[1], FileMode.Create, FileAccess.Write);
            string stext = textBox2.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
            fs.Write(btext,0 , btext.Length);

            fs.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[2], FileMode.Create, FileAccess.Write);
            string stext = textBox3.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
            fs.Write(btext, 0, btext.Length);

            fs.Close();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[3], FileMode.Create, FileAccess.Write);
            string stext = textBox4.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
            fs.Write(btext,0 , btext.Length);

            fs.Close();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[4], FileMode.Create, FileAccess.Write);
            string stext = textBox5.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
            fs.Write(btext,0 , btext.Length);

            fs.Close();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[5], FileMode.Create, FileAccess.Write);
            string stext = textBox6.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
            fs.Write(btext,0 , btext.Length);

            fs.Close();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream(path[6], FileMode.Create, FileAccess.Write);
            string stext = textBox7.Text;
            byte[] btext = Encoding.Default.GetBytes(stext);
            fs.Write(btext, 0, btext.Length);

            fs.Close();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            File.Delete(path[1]);
        }
        private void button10_Click(object sender, EventArgs e)
        {
            File.Delete(path[2]);
        }
        private void button11_Click(object sender, EventArgs e)
        {
            File.Delete(path[3]);
        }
        private void button12_Click(object sender, EventArgs e)
        {
            File.Delete(path[4]);
        }
        private void button13_Click(object sender, EventArgs e)
        {
            File.Delete(path[5]);
        }
    }
}
