namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.a = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.num4 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.num1 = new System.Windows.Forms.Button();
            this.num3 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.button13 = new System.Windows.Forms.Button();
            this.button14 = new System.Windows.Forms.Button();
            this.num2 = new System.Windows.Forms.Button();
            this.button16 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // a
            // 
            this.a.Location = new System.Drawing.Point(278, 108);
            this.a.Margin = new System.Windows.Forms.Padding(4);
            this.a.Name = "a";
            this.a.Size = new System.Drawing.Size(75, 74);
            this.a.TabIndex = 0;
            this.a.Text = "+";
            this.a.UseVisualStyleBackColor = true;
            this.a.Click += new System.EventHandler(this.Calculate);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(278, 191);
            this.button2.Margin = new System.Windows.Forms.Padding(4);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(74, 74);
            this.button2.TabIndex = 1;
            this.button2.Text = "*";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.Calculate);
            // 
            // num4
            // 
            this.num4.Location = new System.Drawing.Point(36, 193);
            this.num4.Margin = new System.Windows.Forms.Padding(4);
            this.num4.Name = "num4";
            this.num4.Size = new System.Drawing.Size(75, 74);
            this.num4.TabIndex = 2;
            this.num4.Text = "4";
            this.num4.UseVisualStyleBackColor = true;
            this.num4.Click += new System.EventHandler(this.AddNum);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(279, 357);
            this.button4.Margin = new System.Windows.Forms.Padding(4);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 74);
            this.button4.TabIndex = 3;
            this.button4.Text = "-";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.Calculate);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(196, 191);
            this.button5.Margin = new System.Windows.Forms.Padding(4);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 74);
            this.button5.TabIndex = 4;
            this.button5.Text = "6";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.AddNum);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(196, 275);
            this.button6.Margin = new System.Windows.Forms.Padding(4);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(75, 74);
            this.button6.TabIndex = 5;
            this.button6.Text = "9";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.AddNum);
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(113, 357);
            this.button7.Margin = new System.Windows.Forms.Padding(4);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(75, 74);
            this.button7.TabIndex = 6;
            this.button7.Text = "0";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.AddNum);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(196, 357);
            this.button8.Margin = new System.Windows.Forms.Padding(4);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(75, 74);
            this.button8.TabIndex = 7;
            this.button8.Text = "=";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.Equal);
            // 
            // num1
            // 
            this.num1.Location = new System.Drawing.Point(36, 109);
            this.num1.Margin = new System.Windows.Forms.Padding(4);
            this.num1.Name = "num1";
            this.num1.Size = new System.Drawing.Size(75, 74);
            this.num1.TabIndex = 8;
            this.num1.Text = "1";
            this.num1.UseVisualStyleBackColor = true;
            this.num1.Click += new System.EventHandler(this.AddNum);
            // 
            // num3
            // 
            this.num3.Location = new System.Drawing.Point(195, 108);
            this.num3.Margin = new System.Windows.Forms.Padding(4);
            this.num3.Name = "num3";
            this.num3.Size = new System.Drawing.Size(75, 74);
            this.num3.TabIndex = 9;
            this.num3.Text = "3";
            this.num3.UseVisualStyleBackColor = true;
            this.num3.Click += new System.EventHandler(this.AddNum);
            // 
            // button11
            // 
            this.button11.Location = new System.Drawing.Point(279, 275);
            this.button11.Margin = new System.Windows.Forms.Padding(4);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(74, 74);
            this.button11.TabIndex = 10;
            this.button11.Text = "/";
            this.button11.UseVisualStyleBackColor = true;
            this.button11.Click += new System.EventHandler(this.Calculate);
            // 
            // button12
            // 
            this.button12.Location = new System.Drawing.Point(113, 275);
            this.button12.Margin = new System.Windows.Forms.Padding(4);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(75, 74);
            this.button12.TabIndex = 11;
            this.button12.Text = "8";
            this.button12.UseVisualStyleBackColor = true;
            this.button12.Click += new System.EventHandler(this.AddNum);
            // 
            // button13
            // 
            this.button13.Location = new System.Drawing.Point(36, 275);
            this.button13.Margin = new System.Windows.Forms.Padding(4);
            this.button13.Name = "button13";
            this.button13.Size = new System.Drawing.Size(75, 74);
            this.button13.TabIndex = 12;
            this.button13.Text = "7";
            this.button13.UseVisualStyleBackColor = true;
            this.button13.Click += new System.EventHandler(this.AddNum);
            // 
            // button14
            // 
            this.button14.Location = new System.Drawing.Point(113, 191);
            this.button14.Margin = new System.Windows.Forms.Padding(4);
            this.button14.Name = "button14";
            this.button14.Size = new System.Drawing.Size(75, 74);
            this.button14.TabIndex = 13;
            this.button14.Text = "5";
            this.button14.UseVisualStyleBackColor = true;
            this.button14.Click += new System.EventHandler(this.AddNum);
            // 
            // num2
            // 
            this.num2.Location = new System.Drawing.Point(113, 108);
            this.num2.Margin = new System.Windows.Forms.Padding(4);
            this.num2.Name = "num2";
            this.num2.Size = new System.Drawing.Size(75, 74);
            this.num2.TabIndex = 14;
            this.num2.Text = "2";
            this.num2.UseVisualStyleBackColor = true;
            this.num2.Click += new System.EventHandler(this.AddNum);
            // 
            // button16
            // 
            this.button16.Location = new System.Drawing.Point(36, 357);
            this.button16.Margin = new System.Windows.Forms.Padding(4);
            this.button16.Name = "button16";
            this.button16.Size = new System.Drawing.Size(75, 74);
            this.button16.TabIndex = 15;
            this.button16.Text = ".";
            this.button16.UseVisualStyleBackColor = true;
            this.button16.Click += new System.EventHandler(this.AddNum);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(78, 32);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(179, 25);
            this.textBox1.TabIndex = 17;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(78, 76);
            this.textBox2.Margin = new System.Windows.Forms.Padding(4);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(179, 25);
            this.textBox2.TabIndex = 18;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(378, 109);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(76, 103);
            this.button1.TabIndex = 19;
            this.button1.Text = "归零";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Reset);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(796, 486);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button16);
            this.Controls.Add(this.num2);
            this.Controls.Add(this.button14);
            this.Controls.Add(this.button13);
            this.Controls.Add(this.button12);
            this.Controls.Add(this.button11);
            this.Controls.Add(this.num3);
            this.Controls.Add(this.num1);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.num4);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.a);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button a;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button num4;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button num1;
        private System.Windows.Forms.Button num3;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button button12;
        private System.Windows.Forms.Button button13;
        private System.Windows.Forms.Button button14;
        private System.Windows.Forms.Button num2;
        private System.Windows.Forms.Button button16;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button1;
    }
}

