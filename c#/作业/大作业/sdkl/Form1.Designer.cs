
namespace 实验
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button5 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.多文本剪贴ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.临时文本ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.文件读取ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.文本ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.文本替换ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.文本插入ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.设置ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Bisque;
            this.button1.Font = new System.Drawing.Font("方正粗黑宋简体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.button1.Location = new System.Drawing.Point(18, 168);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(148, 52);
            this.button1.TabIndex = 1;
            this.button1.Text = "文本剪贴操作";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button5);
            this.groupBox1.Controls.Add(this.button4);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Location = new System.Drawing.Point(71, 94);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(441, 261);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.PeachPuff;
            this.button5.Font = new System.Drawing.Font("方正粗黑宋简体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.button5.Location = new System.Drawing.Point(287, 149);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(88, 52);
            this.button5.TabIndex = 5;
            this.button5.Text = "退出";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.Bisque;
            this.button4.Font = new System.Drawing.Font("方正粗黑宋简体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.button4.Location = new System.Drawing.Point(232, 68);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(173, 52);
            this.button4.TabIndex = 4;
            this.button4.Text = "含数字文本递增";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.Bisque;
            this.button2.Font = new System.Drawing.Font("方正粗黑宋简体", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.button2.Location = new System.Drawing.Point(18, 68);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(148, 52);
            this.button2.TabIndex = 2;
            this.button2.Text = "文本替换";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.BackColor = System.Drawing.Color.BurlyWood;
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem,
            this.文本ToolStripMenuItem,
            this.设置ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(612, 28);
            this.menuStrip1.TabIndex = 4;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.多文本剪贴ToolStripMenuItem,
            this.临时文本ToolStripMenuItem,
            this.文件读取ToolStripMenuItem});
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
            this.文件ToolStripMenuItem.Text = "文件";
            // 
            // 多文本剪贴ToolStripMenuItem
            // 
            this.多文本剪贴ToolStripMenuItem.Name = "多文本剪贴ToolStripMenuItem";
            this.多文本剪贴ToolStripMenuItem.Size = new System.Drawing.Size(167, 26);
            this.多文本剪贴ToolStripMenuItem.Text = "多文本剪贴";
            this.多文本剪贴ToolStripMenuItem.Click += new System.EventHandler(this.多文本剪贴ToolStripMenuItem_Click);
            // 
            // 临时文本ToolStripMenuItem
            // 
            this.临时文本ToolStripMenuItem.Name = "临时文本ToolStripMenuItem";
            this.临时文本ToolStripMenuItem.Size = new System.Drawing.Size(167, 26);
            this.临时文本ToolStripMenuItem.Text = "临时文本";
            this.临时文本ToolStripMenuItem.Click += new System.EventHandler(this.临时文本ToolStripMenuItem_Click_1);
            // 
            // 文件读取ToolStripMenuItem
            // 
            this.文件读取ToolStripMenuItem.Name = "文件读取ToolStripMenuItem";
            this.文件读取ToolStripMenuItem.Size = new System.Drawing.Size(167, 26);
            this.文件读取ToolStripMenuItem.Text = "文件读取";
            this.文件读取ToolStripMenuItem.Click += new System.EventHandler(this.文件读取ToolStripMenuItem_Click);
            // 
            // 文本ToolStripMenuItem
            // 
            this.文本ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文本替换ToolStripMenuItem,
            this.文本插入ToolStripMenuItem});
            this.文本ToolStripMenuItem.Name = "文本ToolStripMenuItem";
            this.文本ToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
            this.文本ToolStripMenuItem.Text = "文本";
            // 
            // 文本替换ToolStripMenuItem
            // 
            this.文本替换ToolStripMenuItem.Name = "文本替换ToolStripMenuItem";
            this.文本替换ToolStripMenuItem.Size = new System.Drawing.Size(152, 26);
            this.文本替换ToolStripMenuItem.Text = "文本替换";
            this.文本替换ToolStripMenuItem.Click += new System.EventHandler(this.文本替换ToolStripMenuItem_Click);
            // 
            // 文本插入ToolStripMenuItem
            // 
            this.文本插入ToolStripMenuItem.Name = "文本插入ToolStripMenuItem";
            this.文本插入ToolStripMenuItem.Size = new System.Drawing.Size(152, 26);
            this.文本插入ToolStripMenuItem.Text = "文本插入";
            this.文本插入ToolStripMenuItem.Click += new System.EventHandler(this.文本插入ToolStripMenuItem_Click);
            // 
            // 设置ToolStripMenuItem
            // 
            this.设置ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.退出ToolStripMenuItem});
            this.设置ToolStripMenuItem.Name = "设置ToolStripMenuItem";
            this.设置ToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
            this.设置ToolStripMenuItem.Text = "设置";
            // 
            // 退出ToolStripMenuItem
            // 
            this.退出ToolStripMenuItem.Name = "退出ToolStripMenuItem";
            this.退出ToolStripMenuItem.Size = new System.Drawing.Size(122, 26);
            this.退出ToolStripMenuItem.Text = "退出";
            this.退出ToolStripMenuItem.Click += new System.EventHandler(this.退出ToolStripMenuItem_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.PapayaWhip;
            this.ClientSize = new System.Drawing.Size(612, 467);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.menuStrip1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.groupBox1.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 多文本剪贴ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 临时文本ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 文本ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 文本替换ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 文本插入ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 设置ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 退出ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 文件读取ToolStripMenuItem;
    }
}

