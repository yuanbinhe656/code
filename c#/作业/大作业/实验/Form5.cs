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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            string dizeng;
            
            

            dizeng = Clipboard.GetText();
            
            char[] dizengt= dizeng.ToCharArray();
            int a,len=dizeng.Length;
            int j = 0;
            
            for (int i = 0; i < len; i++)
            {
                
                string ceshi = Convert.ToString(dizengt[i]);
                if (int.TryParse(ceshi, out a))
                {
                    dizeng = dizeng.Remove(j, 1);

                   
                        if (a == 9)
                        {
                            int c;
                            if (i >= 1)
                            {
                                if (int.TryParse(Convert.ToString(dizengt[i - 1]), out c))
                                {
                                    if (c == 9)
                                    {
                                        dizeng = dizeng.Remove(j - 1, 1);
                                        dizeng = dizeng.Insert(j - 1, "100");
                                    j++;
                                    }
                                    else
                                    {

                                        dizeng = dizeng.Remove(j - 1, 1);
                                        dizeng = dizeng.Insert(j - 1, Convert.ToString((c + 1) * 10));



                                    }
                                }
                                else
                                {

                                    dizeng = dizeng.Insert(j, "10");
                                    j++;
                                }
                            }
                         
                        }
                    else
                    {
                        if (i >= 1)

                        {
                            int c;
                            if (int.TryParse(Convert.ToString(dizengt[i - 1]), out c))
                            {
                                dizeng = dizeng.Remove(j-1, 1);
                                dizeng = dizeng.Insert(j - 1, Convert.ToString(dizengt[i - 1]));
                                dizeng = dizeng.Insert(j, Convert.ToString(a + 1));
                            }
                            else
                                dizeng = dizeng.Insert(j, Convert.ToString(a + 1));
                        }
                    }










                }
                j++;
            }
            //dizeng = dizeng.Insert(2, "34");
            textBox1.Text = dizeng;
            Clipboard.SetDataObject(textBox1.Text);
            // textBox1.Text = Convert.ToString(dizengt[0]);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form5_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Clipboard.SetDataObject(textBox1.Text);
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }
    }
}
