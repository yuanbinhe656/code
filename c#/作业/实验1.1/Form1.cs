using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 实验1._1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Form childForm1 = new Form();
            childForm1.Text = "Child Form 1";
            childForm1.Size = new Size(200, 100);
        

            Form childForm2 = new Form();
            childForm2.Text = "Child Form 2";
            childForm2.Size = new Size(200, 100);
        

            Form childForm3 = new Form();
            childForm3.Text = "Child Form 3";
            childForm3.Size = new Size(200, 100);
         

            this.IsMdiContainer = true;
            childForm1.Show();
            childForm2.Show();
            childForm3.Show();
            childForm1.MdiParent = this;
            childForm2.MdiParent = this;
            childForm3.MdiParent = this;
            

        }
     

        private void button1_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }
        public void ending(int i)
        {
            DialogResult a = MessageBox.Show("请确认是否关闭", "确认对话框", MessageBoxButtons.OK);
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ending(1);
        }
    }
}
