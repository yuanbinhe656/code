namespace 程序检验
{


    public partial class Form1 : Form
    {
        public class tiaojian
        {
            public static int nametxt;
            public int name;
            public string[] stext = { "循环增加", "循环结束可能有多种情况" };
            public string[] vtext = { "循环", "条件" };
            public xunhuan[] xarry;
            public tiaojian[] tarry;
            public int[] num = new int[2];
            static tiaojian()
            {
                nametxt = 1;
            }
            public tiaojian(int[] s)
            {
                name = nametxt;
                xarry = new xunhuan[s[0]];
                tarry =new tiaojian[s[1]];
                nametxt++;

            }
        }
        public class xunhuan
        {
            public static int  nametxt;
            public int name;
            public string[] stext = { "循环增加","循环结束可能有多种情况" };
            public string[] vtext = {"循环","条件"};
            public xunhuan[] xarry;
            public tiaojian[] tarry;
            public int[] num=new int[2];
            static xunhuan()
            {
                nametxt = 1;
            }
            public xunhuan( int[] s)
            {
                name = nametxt;
                xarry = new xunhuan[s[0]];
                tarry = new tiaojian[s[1]];
                nametxt++;

            }
        }


        public Form1()
        {
            InitializeComponent();
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void checkedListBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            
        }
    }
}