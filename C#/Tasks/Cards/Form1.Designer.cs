namespace Cards
{
	partial class Form1
	{
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		/// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
		protected override void Dispose( bool disposing )
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Код, автоматически созданный конструктором форм Windows

		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		private void InitializeComponent()
		{
			this.panel1 = new System.Windows.Forms.Panel();
			this.shapeContainer1 = new Microsoft.VisualBasic.PowerPacks.ShapeContainer();
			this.lineShape1 = new Microsoft.VisualBasic.PowerPacks.LineShape();
			this.button1 = new System.Windows.Forms.Button();
			this.tb_ip = new System.Windows.Forms.TextBox();
			this.tb_port = new System.Windows.Forms.TextBox();
			this.btn_connect = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.lb_status = new System.Windows.Forms.Label();
			this.lb_answer = new System.Windows.Forms.Label();
			this.panel1.SuspendLayout();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.BackColor = System.Drawing.SystemColors.ButtonShadow;
			this.panel1.Controls.Add(this.lb_answer);
			this.panel1.Controls.Add(this.lb_status);
			this.panel1.Controls.Add(this.label1);
			this.panel1.Controls.Add(this.btn_connect);
			this.panel1.Controls.Add(this.tb_port);
			this.panel1.Controls.Add(this.tb_ip);
			this.panel1.Controls.Add(this.button1);
			this.panel1.Controls.Add(this.shapeContainer1);
			this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.panel1.Location = new System.Drawing.Point(0, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(624, 442);
			this.panel1.TabIndex = 0;
			this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
			this.panel1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseClick);
			// 
			// shapeContainer1
			// 
			this.shapeContainer1.Location = new System.Drawing.Point(0, 0);
			this.shapeContainer1.Margin = new System.Windows.Forms.Padding(0);
			this.shapeContainer1.Name = "shapeContainer1";
			this.shapeContainer1.Shapes.AddRange(new Microsoft.VisualBasic.PowerPacks.Shape[] {
            this.lineShape1});
			this.shapeContainer1.Size = new System.Drawing.Size(624, 442);
			this.shapeContainer1.TabIndex = 0;
			this.shapeContainer1.TabStop = false;
			// 
			// lineShape1
			// 
			this.lineShape1.Name = "lineShape1";
			this.lineShape1.X1 = 0;
			this.lineShape1.X2 = 640;
			this.lineShape1.Y1 = 220;
			this.lineShape1.Y2 = 220;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(3, 3);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(61, 23);
			this.button1.TabIndex = 1;
			this.button1.Text = "Run";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// tb_ip
			// 
			this.tb_ip.Location = new System.Drawing.Point(165, 3);
			this.tb_ip.Name = "tb_ip";
			this.tb_ip.Size = new System.Drawing.Size(100, 20);
			this.tb_ip.TabIndex = 2;
			this.tb_ip.Text = "127.0.0.1";
			// 
			// tb_port
			// 
			this.tb_port.Location = new System.Drawing.Point(271, 3);
			this.tb_port.Name = "tb_port";
			this.tb_port.Size = new System.Drawing.Size(59, 20);
			this.tb_port.TabIndex = 3;
			this.tb_port.Text = "8089";
			// 
			// btn_connect
			// 
			this.btn_connect.Location = new System.Drawing.Point(337, 3);
			this.btn_connect.Name = "btn_connect";
			this.btn_connect.Size = new System.Drawing.Size(67, 23);
			this.btn_connect.TabIndex = 4;
			this.btn_connect.Text = "Connect";
			this.btn_connect.UseVisualStyleBackColor = true;
			this.btn_connect.Click += new System.EventHandler(this.btn_connect_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(410, 10);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(110, 13);
			this.label1.TabIndex = 5;
			this.label1.Text = "Статус соединения: ";
			// 
			// lb_status
			// 
			this.lb_status.AutoSize = true;
			this.lb_status.Location = new System.Drawing.Point(524, 10);
			this.lb_status.Name = "lb_status";
			this.lb_status.Size = new System.Drawing.Size(89, 13);
			this.lb_status.TabIndex = 6;
			this.lb_status.Text = "Нет соединения";
			// 
			// lb_answer
			// 
			this.lb_answer.AutoSize = true;
			this.lb_answer.Location = new System.Drawing.Point(503, 23);
			this.lb_answer.Name = "lb_answer";
			this.lb_answer.Size = new System.Drawing.Size(63, 13);
			this.lb_answer.TabIndex = 7;
			this.lb_answer.Text = "Ответа нет";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(624, 442);
			this.Controls.Add(this.panel1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.panel1.ResumeLayout(false);
			this.panel1.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel panel1;
		private Microsoft.VisualBasic.PowerPacks.ShapeContainer shapeContainer1;
		private Microsoft.VisualBasic.PowerPacks.LineShape lineShape1;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.TextBox tb_port;
		private System.Windows.Forms.TextBox tb_ip;
		private System.Windows.Forms.Label lb_status;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button btn_connect;
		private System.Windows.Forms.Label lb_answer;
	}
}

