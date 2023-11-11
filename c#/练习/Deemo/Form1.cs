namespace Deemo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void md5ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form2 fwin = new Form2();
            fwin.Show();
            
        }
    }
}