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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {

        }
        public string seek;
        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult dr = openFileDialog1.ShowDialog();
            if (dr == DialogResult.OK)
            {
                string path = openFileDialog1.FileName;
                FileStream fd = new FileStream(path, FileMode.Open, FileAccess.Read);
                byte[] mo = new byte[fd.Length];
                fd.Read(mo, 0, mo.Length);
                richTextBox1.Text = Encoding.Default.GetString(mo);
                fd.Close();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {

            DialogResult sr = saveFileDialog1.ShowDialog();
            if (sr == DialogResult.OK)
            {
                string na = saveFileDialog1.FileName;
                FileStream sa = new FileStream(na, FileMode.Create);
                string stext = richTextBox1.Text;
                byte[] btext = Encoding.Default.GetBytes(stext);
                sa.Write(btext, 0, btext.Length);
                sa.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = false;
            groupBox2.Visible = true;
        }

        private void toolStripLabel1_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            seek = textBox1.Text;
            groupBox2.Visible = false;
            groupBox1.Visible = true;
            int[] a;
            int j,i = 0;
            string text = richTextBox1.Text;
            j = text.Length;
            while (text.IndexOf(seek,i,j)!=-1)
            {
                i = text.IndexOf(seek,i,j);
                richTextBox1.Select(i, seek.Length);
                richTextBox1.SelectionColor = Color.Tomato;
                i = i + seek.Length;
                j = text.Length - i;
                if (i + seek.Length == text.Length)
                    break;
            }
           
           
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Clipboard.SetDataObject(richTextBox1.Text);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowDialog();
            richTextBox1.SelectionFont = fontDialog1.Font;
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }
    }
}
