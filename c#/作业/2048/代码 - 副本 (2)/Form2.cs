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


namespace 代码
{

    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {

        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
           
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        public void add(int a)
        {
            Random rand = new Random();
            int i = 1;
            while (i == 1)
            {
                int num;
                num = rand.Next(1, 10);
                switch (num)
                {
                    case 1:
                        if (label1.Text.Length == 0)
                        {
                            label1.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 2:
                        if (label2.Text.Length == 0)
                        {
                            label2.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 3:
                        if (label3.Text.Length == 0)
                        {
                            label3.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 4:
                        if (label4.Text.Length == 0)
                        {
                            label4.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 5:
                        if (label5.Text.Length == 0)
                        {
                            label5.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 6:
                        if (label6.Text.Length == 0)
                        {
                            label6.Text = "2";
                            i = 0;
                            break;
                        }
                        else

                            break;
                    case 7:
                        if (label7.Text.Length == 0)
                        {
                            label7.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 8:
                        if (label8.Text.Length == 0)
                        {
                            label8.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                    case 9:
                        if (label9.Text.Length == 0)
                        {
                            label9.Text = "2";
                            i = 0;
                            break;
                        }
                        else
                            break;
                }



            }

        }
        public void beging(int i)
        {
            label12.Text = "000";
            label1.Text = "";
            label2.Text = "";
            label3.Text = "";

            label4.Text = "";
            label5.Text = "";
            label6.Text = "";
            label7.Text = "";
            label8.Text = "";
            label9.Text = "";
        }

        public int top=0;

        public void ending(int x)
        {
            string tops = Convert.ToString(top);
            if (label1.Text.Length != 0 & label2.Text.Length != 0 & label3.Text.Length != 0 & label4.Text.Length != 0 & label5.Text.Length != 0 & label6.Text.Length != 0 & label7.Text.Length != 0 & label8.Text.Length != 0 & label9.Text.Length != 0)
            {

                int its = Convert.ToInt32(label12.Text);

                if (top <= its)
                {
                    top = its;
                    DialogResult a = MessageBox.Show("恭喜您，突破了记录！"+"您的最终成绩为：" + label12.Text + "\n是否开始一局新游戏?", "最终成绩", MessageBoxButtons.YesNo);
                    if (a == DialogResult.Yes)
                    {
                        this.Hide();
                        Form2 form2 = new Form2();
                        form2.ShowDialog();
                        this.Close();
                    }
                    else
                    {
                        this.Hide();
                        
                       
                        this.Close();
                    }
                }
                else
                {
                    DialogResult a = MessageBox.Show("您的历史最好成绩为："+tops+"\n您的最终成绩为：" + label12.Text + "\n是否开始一局新游戏?", "最终成绩", MessageBoxButtons.YesNo);
                    if (a == DialogResult.Yes)
                    {
                        this.Hide();
                        Form2 form2 = new Form2();
                        form2.ShowDialog();
                        this.Close();
                    }
                    else
                    {
                        this.Hide();
                        
                        this.Close();
                    }
                }
                
                


            }

        }

            private void label8_Click(object sender, EventArgs e)
        {
            
        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form2 form2 = new Form2();
            form2.ShowDialog();
            this.Close();
        }

        private void Form2_KeyDown(object sender, KeyEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (label4.Text == label1.Text & label4.Text.Length != 0)
            {
                int a = Convert.ToInt32(label1.Text);
                a = 2 * a;
                
                label1.Text = Convert.ToString(a);
                a=a+ Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label4.Text = "";
            }
            if (label4.Text == label7.Text & label4.Text.Length != 0)
            {
                int a =  Convert.ToInt32(label4.Text);
                a = 2 * a;
                label4.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label7.Text = "";
            }
            if (label1.Text == label7.Text & label1.Text.Length != 0 & label4.Text.Length == 0)
            {
                int a = Convert.ToInt32(label1.Text);
                a = 2 * a;
                label1.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label7.Text = "";
            }
            if (label1.Text.Length == 0)
            {
                if (label4.Text.Length != 0)
                {
                    label1.Text = label4.Text;
                    label4.Text = label7.Text;
                    label7.Text = "";
                }
                else
                {
                    label1.Text = label7.Text;
                    label7.Text = "";
                }
            }
            else
            {
                if (label4.Text.Length == 0)
                {
                    label4.Text = label7.Text;
                    label7.Text = "";
                }
            }
            if (label5.Text == label2.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label2.Text);
                a = 2 * a;
                label2.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label5.Text = "";
            }
            if (label5.Text == label8.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label5.Text);
                a = 2 * a;
                label5.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label8.Text = "";
            }
            if (label2.Text == label8.Text & label2.Text.Length != 0 & label5.Text.Length == 0)
            {
                int a = Convert.ToInt32(label2.Text);
                a = 2 * a;
                label2.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label8.Text = "";
            }
            if (label2.Text.Length == 0)
            {
                if (label5.Text.Length != 0)
                {
                    label2.Text = label5.Text;
                    label5.Text = label8.Text;
                    label8.Text = "";
                }
                else
                {
                    label2.Text = label8.Text;
                    label8.Text = "";
                }
            }
            else
            {
                if (label5.Text.Length == 0)
                {
                    label5.Text = label8.Text;
                    label8.Text = "";
                }
            }

            if (label6.Text == label3.Text & label6.Text.Length != 0)
            {
                int a = Convert.ToInt32(label3.Text);
                a = 2 * a;
                label3.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label6.Text = "";
            }
            if (label6.Text == label9.Text & label6.Text.Length != 0)
            {
                int a = Convert.ToInt32(label6.Text);
                a = 2 * a;
                label6.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label9.Text = "";
            }
            if (label3.Text == label9.Text & label3.Text.Length != 0 & label6.Text.Length == 0)
            {
                int a = Convert.ToInt32(label3.Text);
                a = 2 * a;
                label3.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label9.Text = "";
            }
            if (label3.Text.Length == 0)
            {
                if (label6.Text.Length != 0)
                {
                    label3.Text = label6.Text;
                    label6.Text = label9.Text;
                    label9.Text = "";
                }
                else
                {
                    label3.Text = label9.Text;
                    label9.Text = "";
                }
            }
            else
            {
                if (label6.Text.Length == 0)
                {
                    label6.Text = label9.Text;
                    label9.Text = "";
                }
            }
            add(0);
            ending(1);     
        }

        private void button6_Click(object sender, EventArgs e)
        {
            beging(1);
            add(1);
            
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (label4.Text == label7.Text & label4.Text.Length != 0)
            {
                int a = Convert.ToInt32(label7.Text);
                a = 2 * a;
                label7.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label4.Text = "";
            }
            if (label4.Text == label1.Text & label4.Text.Length != 0)
            {
                int a = Convert.ToInt32(label4.Text);
                a = 2 * a;
                label4.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label1.Text = "";
            }
            if (label7.Text == label1.Text & label7.Text.Length != 0 & label4.Text.Length == 0)
            {
                int a = Convert.ToInt32(label7.Text);
                a = 2 * a;
                label7.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label1.Text = "";
            }
            if (label7.Text.Length == 0)
            {
                if (label4.Text.Length != 0)
                {
                    label7.Text = label4.Text;
                    label4.Text = label1.Text;
                    label1.Text = "";
                }
                else
                {
                    label7.Text = label1.Text;
                    label1.Text = "";
                }
            }
            else
            {
                if (label4.Text.Length == 0)
                {
                    label4.Text = label1.Text;
                    label1.Text = "";
                }
            }
            if (label5.Text == label8.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label8.Text);
                a = 2 * a;
                label8.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label5.Text = "";
            }
            if (label5.Text == label2.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label5.Text);
                a = 2 * a;
                label5.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label2.Text = "";
            }
            if (label8.Text == label2.Text & label8.Text.Length != 0 & label5.Text.Length == 0)
            {
                int a = Convert.ToInt32(label8.Text);
                a = 2 * a;
                label8.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label2.Text = "";
            }
            if (label8.Text.Length == 0)
            {
                if (label5.Text.Length != 0)
                {
                    label8.Text = label5.Text;
                    label5.Text = label2.Text;
                    label2.Text = "";
                }
                else
                {
                    label8.Text = label2.Text;
                    label2.Text = "";
                }
            }
            else
            {
                if (label5.Text.Length == 0)
                {
                    label5.Text = label2.Text;
                    label2.Text = "";
                }
            }

            if (label6.Text == label9.Text & label6.Text.Length != 0)
            {
                int a = Convert.ToInt32(label9.Text);
                a = 2 * a;
                label9.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label6.Text = "";
            }
            if (label6.Text == label3.Text & label6.Text.Length != 0)
            {
                int a = Convert.ToInt32(label6.Text);
                a = 2 * a;
                label6.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label3.Text = "";
            }
            if (label9.Text == label3.Text & label9.Text.Length != 0 & label6.Text.Length == 0)
            {
                int a = Convert.ToInt32(label9.Text);
                a = 2 * a;
                label9.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label3.Text = "";
            }
            if (label9.Text.Length == 0)
            {
                if (label6.Text.Length != 0)
                {
                    label9.Text = label6.Text;
                    label6.Text = label3.Text;
                    label3.Text = "";
                }
                else
                {
                    label9.Text = label3.Text;
                    label3.Text = "";
                }
            }
            else
            {
                if (label6.Text.Length == 0)
                {
                    label6.Text = label3.Text;
                    label3.Text = "";
                }
            }
            add(0);
            ending(1);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (label2.Text == label3.Text & label2.Text.Length != 0)
            {
                int a = Convert.ToInt32(label3.Text);
                a = 2 * a;

                label3.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label2.Text = "";
            }
            if (label2.Text == label1.Text & label2.Text.Length != 0)
            {
                int a = Convert.ToInt32(label2.Text);
                a = 2 * a;
                label2.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label1.Text = "";
            }
            if (label3.Text == label1.Text & label3.Text.Length != 0 & label2.Text.Length == 0)
            {
                int a = Convert.ToInt32(label3.Text);
                a = 2 * a;
                label3.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label1.Text = "";
            }
            if (label3.Text.Length == 0)
            {
                if (label2.Text.Length != 0)
                {
                    label3.Text = label2.Text;
                    label2.Text = label1.Text;
                    label1.Text = "";
                }
                else
                {
                    label3.Text = label1.Text;
                    label1.Text = "";
                }
            }
            else
            {
                if (label2.Text.Length == 0)
                {
                    label2.Text = label1.Text;
                    label1.Text = "";
                }
            }
            if (label5.Text == label6.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label6.Text);
                a = 2 * a;
                label6.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label5.Text = "";
            }
            if (label5.Text == label4.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label5.Text);
                a = 2 * a;
                label5.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label4.Text = "";
            }
            if (label6.Text == label4.Text & label6.Text.Length != 0 & label5.Text.Length == 0)
            {
                int a = Convert.ToInt32(label6.Text);
                a = 2 * a;
                label6.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label4.Text = "";
            }
            if (label6.Text.Length == 0)
            {
                if (label5.Text.Length != 0)
                {
                    label6.Text = label5.Text;
                    label5.Text = label4.Text;
                    label4.Text = "";
                }
                else
                {
                    label6.Text = label4.Text;
                    label4.Text = "";
                }
            }
            else
            {
                if (label5.Text.Length == 0)
                {
                    label5.Text = label4.Text;
                    label4.Text = "";
                }
            }

            if (label8.Text == label9.Text & label8.Text.Length != 0)
            {
                int a = Convert.ToInt32(label9.Text);
                a = 2 * a;
                label9.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label8.Text = "";
            }
            if (label8.Text == label7.Text & label8.Text.Length != 0)
            {
                int a = Convert.ToInt32(label8.Text);
                a = 2 * a;
                label8.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label7.Text = "";
            }
            if (label9.Text == label7.Text & label9.Text.Length != 0 & label8.Text.Length == 0)
            {
                int a = Convert.ToInt32(label9.Text);
                a = 2 * a;
                label9.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label7.Text = "";
            }
            if (label9.Text.Length == 0)
            {
                if (label8.Text.Length != 0)
                {
                    label9.Text = label8.Text;
                    label8.Text = label7.Text;
                    label7.Text = "";
                }
                else
                {
                    label9.Text = label7.Text;
                    label7.Text = "";
                }
            }
            else
            {
                if (label8.Text.Length == 0)
                {
                    label8.Text = label7.Text;
                    label7.Text = "";
                }
            }
            add(0);
            ending(1);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (label2.Text == label1.Text & label2.Text.Length != 0)
            {
                int a = Convert.ToInt32(label1.Text);
                a = 2 * a;
                label1.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label2.Text = "";
            }
            if (label2.Text == label3.Text & label2.Text.Length != 0)
            {
                int a = Convert.ToInt32(label2.Text);
                a = 2 * a;
                label2.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label3.Text = "";
            }
            if (label1.Text == label3.Text & label1.Text.Length != 0 & label2.Text.Length == 0)
            {
                int a = Convert.ToInt32(label1.Text);
                a = 2 * a;
                label1.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label3.Text = "";
            }
            if (label1.Text.Length == 0)
            {
                if (label2.Text.Length != 0)
                {
                    label1.Text = label2.Text;
                    label2.Text = label3.Text;
                    label3.Text = "";
                }
                else
                {
                    label1.Text = label3.Text;
                    label3.Text = "";
                }
            }
            else
            {
                if (label2.Text.Length == 0)
                {
                    label2.Text = label3.Text;
                    label3.Text = "";
                }
            }
            if (label5.Text == label4.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label4.Text);
                a = 2 * a;
                label4.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label5.Text = "";
            }
            if (label5.Text == label6.Text & label5.Text.Length != 0)
            {
                int a = Convert.ToInt32(label5.Text);
                a = 2 * a;
                label5.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label6.Text = "";
            }
            if (label4.Text == label6.Text & label4.Text.Length != 0 & label5.Text.Length == 0)
            {
                int a = Convert.ToInt32(label4.Text);
                a = 2 * a;
                label4.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label6.Text = "";
            }
            if (label4.Text.Length == 0)
            {
                if (label5.Text.Length != 0)
                {
                    label4.Text = label5.Text;
                    label5.Text = label6.Text;
                    label6.Text = "";
                }
                else
                {
                    label4.Text = label6.Text;
                    label6.Text = "";
                }
            }
            else
            {
                if (label5.Text.Length == 0)
                {
                    label5.Text = label6.Text;
                    label6.Text = "";
                }
            }

            if (label8.Text == label7.Text & label8.Text.Length != 0)
            {
                int a = Convert.ToInt32(label7.Text);
                a = 2 * a;
                label7.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label8.Text = "";
            }
            if (label8.Text == label9.Text & label8.Text.Length != 0)
            {
                int a = Convert.ToInt32(label8.Text);
                a = 2 * a;
                label8.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label9.Text = "";
            }
            if (label7.Text == label9.Text & label7.Text.Length != 0 & label8.Text.Length == 0)
            {
                int a = Convert.ToInt32(label7.Text);
                a = 2 * a;
                label7.Text = Convert.ToString(a);
                a = a + Convert.ToInt32(label12.Text);
                label12.Text = Convert.ToString(a);
                label9.Text = "";
            }
            if (label7.Text.Length == 0)
            {
                if (label8.Text.Length != 0)
                {
                    label7.Text = label8.Text;
                    label8.Text = label9.Text;
                    label9.Text = "";
                }
                else
                {
                    label7.Text = label9.Text;
                    label9.Text = "";
                }
            }
            else
            {
                if (label8.Text.Length == 0)
                {
                    label8.Text = label9.Text;
                    label9.Text = "";
                }
            }
            add(0);
            ending(1);
        }
    }
}
