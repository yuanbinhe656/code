
namespace WinFormsApp1
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.选择模式ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.简单模式ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.入门模式ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.地狱模式ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.查看历史记录ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.本人历史记录ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.玩家历史记录ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.gAMEToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.选择模式ToolStripMenuItem,
            this.查看历史记录ToolStripMenuItem,
            this.gAMEToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(704, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 选择模式ToolStripMenuItem
            // 
            this.选择模式ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.简单模式ToolStripMenuItem,
            this.入门模式ToolStripMenuItem,
            this.地狱模式ToolStripMenuItem});
            this.选择模式ToolStripMenuItem.Name = "选择模式ToolStripMenuItem";
            this.选择模式ToolStripMenuItem.Size = new System.Drawing.Size(83, 24);
            this.选择模式ToolStripMenuItem.Text = "选择模式";
            // 
            // 简单模式ToolStripMenuItem
            // 
            this.简单模式ToolStripMenuItem.Name = "简单模式ToolStripMenuItem";
            this.简单模式ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.简单模式ToolStripMenuItem.Text = "简单模式";
            // 
            // 入门模式ToolStripMenuItem
            // 
            this.入门模式ToolStripMenuItem.Name = "入门模式ToolStripMenuItem";
            this.入门模式ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.入门模式ToolStripMenuItem.Text = "入门模式";
            // 
            // 地狱模式ToolStripMenuItem
            // 
            this.地狱模式ToolStripMenuItem.Name = "地狱模式ToolStripMenuItem";
            this.地狱模式ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.地狱模式ToolStripMenuItem.Text = "地狱模式";
            // 
            // 查看历史记录ToolStripMenuItem
            // 
            this.查看历史记录ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.本人历史记录ToolStripMenuItem,
            this.玩家历史记录ToolStripMenuItem});
            this.查看历史记录ToolStripMenuItem.Name = "查看历史记录ToolStripMenuItem";
            this.查看历史记录ToolStripMenuItem.Size = new System.Drawing.Size(113, 24);
            this.查看历史记录ToolStripMenuItem.Text = "查看历史记录";
            // 
            // 本人历史记录ToolStripMenuItem
            // 
            this.本人历史记录ToolStripMenuItem.Name = "本人历史记录ToolStripMenuItem";
            this.本人历史记录ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.本人历史记录ToolStripMenuItem.Text = "本人历史记录";
            // 
            // 玩家历史记录ToolStripMenuItem
            // 
            this.玩家历史记录ToolStripMenuItem.Name = "玩家历史记录ToolStripMenuItem";
            this.玩家历史记录ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.玩家历史记录ToolStripMenuItem.Text = "玩家历史记录";
            // 
            // gAMEToolStripMenuItem
            // 
            this.gAMEToolStripMenuItem.Name = "gAMEToolStripMenuItem";
            this.gAMEToolStripMenuItem.Size = new System.Drawing.Size(112, 24);
            this.gAMEToolStripMenuItem.Text = "2048 GAME ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(474, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(578, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 20);
            this.label2.TabIndex = 2;
            this.label2.Text = "SCIRE";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(704, 450);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 选择模式ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 简单模式ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 入门模式ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 地狱模式ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 查看历史记录ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 本人历史记录ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 玩家历史记录ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem gAMEToolStripMenuItem;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

