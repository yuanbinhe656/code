using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private double temp = 0;
        private char myoperator = ' ';
        private void label1_Click(object sender, EventArgs e)
        {

        }
        private void AddNum(object sender,EventArgs e)
        {
            Button button = (Button)sender;
            textBox2.Text += button.Text;
        }
        private void Reset(object sender,EventArgs e)
        {
            temp = 0;
            myoperator=' ';
            textBox1.Text="";
            textBox2.Text = "";
        }
        private void Calculate(object sender,EventArgs e)
        {
            Button button=(Button)sender;
            if(double.TryParse(textBox2.Text,out temp))
            {
                myoperator=button.Text[0];
                textBox1.Text=temp.ToString()+' '+myoperator;
                textBox2.Text="";
            }
            else
            {
                Reset(sender,e);
            }
        }
        private void Equal(object sender,EventArgs e)
        {
            double temp2;
            if(!double.TryParse(textBox2.Text,out temp2))
            {
                Reset(sender,e);
                return;
            }
            switch (myoperator)
            {
                case '+':
                    temp+=temp2;
                    textBox1.Text = "";
                    textBox2.Text = temp.ToString();
                    break;
                case'-':
                    temp-=temp2;
                    textBox1.Text = "";
                    textBox2.Text = temp.ToString();
                    break;
                case '*':
                    temp*=temp2;;
                    textBox1.Text = "";
                    textBox2.Text = temp.ToString();
                    break;
                case'/':
                    if (temp2 == 0)
                    {
                        textBox1.Text = "除数不能为0";
                        textBox2.Text = "请重新输入";
                    }
                    else
                    {
                        temp = temp / temp2;
                        textBox1.Text = "";
                        textBox2.Text = temp.ToString();
                    }
                        
                   
                    break;
                    
                   
                default:
                    break;
            }

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
