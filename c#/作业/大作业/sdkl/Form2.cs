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
    
    public partial class Form2 : Form
    {
        
        public Form2()
        {
            InitializeComponent();
        }

        
        public string date;
        private void button1_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = false;
            groupBox2.Visible = true;
           
            date = richTextBox1.Text;
        }
        public List<string> dateben = new List<string>();
        public List<string> datenew = new List<string>();
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        
        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
           
            dateben.Add(textBox1.Text);
            datenew.Add(textBox2.Text);
            textBox1.Text = "";
            textBox2.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            dateben.Add(textBox1.Text);
            datenew.Add(textBox2.Text);
            groupBox1.Visible = true;
            groupBox2.Visible = false;
            string mid;
            for (int i = 0; i < dateben.Count; i++)
            {
                mid = Convert.ToString(i);
                date=date.Replace(dateben[i], "aaa" + mid);
            }
            for (int i = 0; i < datenew.Count; i++)
            {
                mid = Convert.ToString(i);
                date=date.Replace("aaa" + mid,datenew[i] );
            }
            richTextBox1.Text = date;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            Clipboard.SetDataObject(richTextBox1.Text);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = Clipboard.GetText();
        }
    }
}
