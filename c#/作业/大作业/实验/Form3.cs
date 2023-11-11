using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length != 0)
            { Clipboard.SetDataObject(textBox1.Text); }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox2.Text.Length != 0)
            { Clipboard.SetDataObject(textBox2.Text); }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (textBox3.Text.Length != 0)
            { Clipboard.SetDataObject(textBox3.Text); }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (textBox4.Text.Length != 0)
            { Clipboard.SetDataObject(textBox4.Text); }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (textBox5.Text.Length != 0)
            { Clipboard.SetDataObject(textBox5.Text); }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (textBox6.Text.Length != 0)
            { Clipboard.SetDataObject(textBox6.Text); }
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text = Clipboard.GetText();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox2.Text = Clipboard.GetText();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox3.Text = Clipboard.GetText();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox4.Text = Clipboard.GetText();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            textBox5.Text = Clipboard.GetText();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            textBox6.Text = Clipboard.GetText();
        }
    }
}
