
namespace WeightConvertor
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.InputText = new System.Windows.Forms.TextBox();
            this.mgBox = new System.Windows.Forms.TextBox();
            this.gramBox = new System.Windows.Forms.TextBox();
            this.kgBox = new System.Windows.Forms.TextBox();
            this.tonBox = new System.Windows.Forms.TextBox();
            this.btnConvert = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // InputText
            // 
            this.InputText.Font = new System.Drawing.Font("굴림", 14F);
            this.InputText.Location = new System.Drawing.Point(12, 12);
            this.InputText.Name = "InputText";
            this.InputText.Size = new System.Drawing.Size(200, 29);
            this.InputText.TabIndex = 0;
            // 
            // mgBox
            // 
            this.mgBox.Location = new System.Drawing.Point(12, 59);
            this.mgBox.Name = "mgBox";
            this.mgBox.ReadOnly = true;
            this.mgBox.Size = new System.Drawing.Size(150, 21);
            this.mgBox.TabIndex = 1;
            this.mgBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // gramBox
            // 
            this.gramBox.Location = new System.Drawing.Point(12, 86);
            this.gramBox.Name = "gramBox";
            this.gramBox.ReadOnly = true;
            this.gramBox.Size = new System.Drawing.Size(150, 21);
            this.gramBox.TabIndex = 1;
            this.gramBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // kgBox
            // 
            this.kgBox.Location = new System.Drawing.Point(12, 113);
            this.kgBox.Name = "kgBox";
            this.kgBox.ReadOnly = true;
            this.kgBox.Size = new System.Drawing.Size(150, 21);
            this.kgBox.TabIndex = 1;
            this.kgBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // tonBox
            // 
            this.tonBox.Location = new System.Drawing.Point(12, 140);
            this.tonBox.Name = "tonBox";
            this.tonBox.ReadOnly = true;
            this.tonBox.Size = new System.Drawing.Size(150, 21);
            this.tonBox.TabIndex = 1;
            this.tonBox.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnConvert
            // 
            this.btnConvert.Location = new System.Drawing.Point(218, 12);
            this.btnConvert.Name = "btnConvert";
            this.btnConvert.Size = new System.Drawing.Size(75, 29);
            this.btnConvert.TabIndex = 3;
            this.btnConvert.Text = "변환";
            this.btnConvert.UseVisualStyleBackColor = true;
            this.btnConvert.Click += new System.EventHandler(this.btnConvert_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("굴림", 12F);
            this.label4.Location = new System.Drawing.Point(168, 141);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 16);
            this.label4.TabIndex = 2;
            this.label4.Text = "톤(t)";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("굴림", 12F);
            this.label3.Location = new System.Drawing.Point(168, 115);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(101, 16);
            this.label3.TabIndex = 2;
            this.label3.Text = "킬로그램(kg)";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("굴림", 12F);
            this.label2.Location = new System.Drawing.Point(168, 89);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "그램(g)";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 12F);
            this.label1.Location = new System.Drawing.Point(168, 62);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(106, 16);
            this.label1.TabIndex = 2;
            this.label1.Text = "밀리그램(mg)";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(342, 178);
            this.Controls.Add(this.btnConvert);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tonBox);
            this.Controls.Add(this.kgBox);
            this.Controls.Add(this.gramBox);
            this.Controls.Add(this.mgBox);
            this.Controls.Add(this.InputText);
            this.Name = "Form1";
            this.Text = "무게 변환기 ver 1.0.0";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox InputText;
        private System.Windows.Forms.TextBox mgBox;
        private System.Windows.Forms.TextBox gramBox;
        private System.Windows.Forms.TextBox kgBox;
        private System.Windows.Forms.TextBox tonBox;
        private System.Windows.Forms.Button btnConvert;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}

