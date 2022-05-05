
namespace AnimalShelter
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
            this.CusCreate = new System.Windows.Forms.Button();
            this.CusDetailPanel = new System.Windows.Forms.Panel();
            this.CusQualified = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.CusDescription = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.CusAddress = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.CusAge = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.CusFullName = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.CusNewPanel = new System.Windows.Forms.Panel();
            this.NewDescription = new System.Windows.Forms.TextBox();
            this.NewAddress = new System.Windows.Forms.TextBox();
            this.NewBirthday = new System.Windows.Forms.TextBox();
            this.NewFirstName = new System.Windows.Forms.TextBox();
            this.NewLastName = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.CusListPanel = new System.Windows.Forms.Panel();
            this.CusList = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.새입양자ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label11 = new System.Windows.Forms.Label();
            this.CusPetInfo = new System.Windows.Forms.Label();
            this.CusDetailPanel.SuspendLayout();
            this.CusNewPanel.SuspendLayout();
            this.CusListPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.CusList)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // CusCreate
            // 
            this.CusCreate.Location = new System.Drawing.Point(163, 324);
            this.CusCreate.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.CusCreate.Name = "CusCreate";
            this.CusCreate.Size = new System.Drawing.Size(154, 33);
            this.CusCreate.TabIndex = 8;
            this.CusCreate.Text = "입양자 생성";
            this.CusCreate.UseVisualStyleBackColor = true;
            this.CusCreate.Click += new System.EventHandler(this.CusCreate_Click);
            // 
            // CusDetailPanel
            // 
            this.CusDetailPanel.Controls.Add(this.CusPetInfo);
            this.CusDetailPanel.Controls.Add(this.CusQualified);
            this.CusDetailPanel.Controls.Add(this.label5);
            this.CusDetailPanel.Controls.Add(this.CusDescription);
            this.CusDetailPanel.Controls.Add(this.label11);
            this.CusDetailPanel.Controls.Add(this.label6);
            this.CusDetailPanel.Controls.Add(this.CusAddress);
            this.CusDetailPanel.Controls.Add(this.label3);
            this.CusDetailPanel.Controls.Add(this.CusAge);
            this.CusDetailPanel.Controls.Add(this.label2);
            this.CusDetailPanel.Controls.Add(this.CusFullName);
            this.CusDetailPanel.Controls.Add(this.label1);
            this.CusDetailPanel.Location = new System.Drawing.Point(377, 12);
            this.CusDetailPanel.Name = "CusDetailPanel";
            this.CusDetailPanel.Size = new System.Drawing.Size(346, 373);
            this.CusDetailPanel.TabIndex = 9;
            // 
            // CusQualified
            // 
            this.CusQualified.AutoSize = true;
            this.CusQualified.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CusQualified.Location = new System.Drawing.Point(84, 79);
            this.CusQualified.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.CusQualified.Name = "CusQualified";
            this.CusQualified.Size = new System.Drawing.Size(60, 25);
            this.CusQualified.TabIndex = 19;
            this.CusQualified.Text = "label2";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label5.Location = new System.Drawing.Point(17, 85);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 15);
            this.label5.TabIndex = 18;
            this.label5.Text = "성인 여부 : ";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // CusDescription
            // 
            this.CusDescription.AutoSize = true;
            this.CusDescription.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CusDescription.Location = new System.Drawing.Point(84, 141);
            this.CusDescription.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.CusDescription.Name = "CusDescription";
            this.CusDescription.Size = new System.Drawing.Size(60, 25);
            this.CusDescription.TabIndex = 17;
            this.CusDescription.Text = "label2";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label6.Location = new System.Drawing.Point(17, 141);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(64, 25);
            this.label6.TabIndex = 16;
            this.label6.Text = "설명 : ";
            // 
            // CusAddress
            // 
            this.CusAddress.AutoSize = true;
            this.CusAddress.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CusAddress.Location = new System.Drawing.Point(84, 108);
            this.CusAddress.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.CusAddress.Name = "CusAddress";
            this.CusAddress.Size = new System.Drawing.Size(60, 25);
            this.CusAddress.TabIndex = 15;
            this.CusAddress.Text = "label2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label3.Location = new System.Drawing.Point(17, 108);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(58, 25);
            this.label3.TabIndex = 14;
            this.label3.Text = "주소 :";
            // 
            // CusAge
            // 
            this.CusAge.AutoSize = true;
            this.CusAge.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CusAge.Location = new System.Drawing.Point(84, 50);
            this.CusAge.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.CusAge.Name = "CusAge";
            this.CusAge.Size = new System.Drawing.Size(60, 25);
            this.CusAge.TabIndex = 13;
            this.CusAge.Text = "label2";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(17, 50);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 25);
            this.label2.TabIndex = 12;
            this.label2.Text = "나이 : ";
            // 
            // CusFullName
            // 
            this.CusFullName.AutoSize = true;
            this.CusFullName.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CusFullName.Location = new System.Drawing.Point(84, 19);
            this.CusFullName.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.CusFullName.Name = "CusFullName";
            this.CusFullName.Size = new System.Drawing.Size(60, 25);
            this.CusFullName.TabIndex = 11;
            this.CusFullName.Text = "label2";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(17, 19);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(64, 25);
            this.label1.TabIndex = 10;
            this.label1.Text = "이름 : ";
            // 
            // CusNewPanel
            // 
            this.CusNewPanel.Controls.Add(this.NewDescription);
            this.CusNewPanel.Controls.Add(this.NewAddress);
            this.CusNewPanel.Controls.Add(this.CusCreate);
            this.CusNewPanel.Controls.Add(this.NewBirthday);
            this.CusNewPanel.Controls.Add(this.NewFirstName);
            this.CusNewPanel.Controls.Add(this.NewLastName);
            this.CusNewPanel.Controls.Add(this.label10);
            this.CusNewPanel.Controls.Add(this.label9);
            this.CusNewPanel.Controls.Add(this.label8);
            this.CusNewPanel.Controls.Add(this.label7);
            this.CusNewPanel.Controls.Add(this.label4);
            this.CusNewPanel.Location = new System.Drawing.Point(341, 377);
            this.CusNewPanel.Name = "CusNewPanel";
            this.CusNewPanel.Size = new System.Drawing.Size(352, 373);
            this.CusNewPanel.TabIndex = 10;
            this.CusNewPanel.Visible = false;
            // 
            // NewDescription
            // 
            this.NewDescription.Location = new System.Drawing.Point(73, 150);
            this.NewDescription.Multiline = true;
            this.NewDescription.Name = "NewDescription";
            this.NewDescription.Size = new System.Drawing.Size(244, 167);
            this.NewDescription.TabIndex = 9;
            // 
            // NewAddress
            // 
            this.NewAddress.Location = new System.Drawing.Point(73, 119);
            this.NewAddress.Name = "NewAddress";
            this.NewAddress.Size = new System.Drawing.Size(244, 29);
            this.NewAddress.TabIndex = 8;
            // 
            // NewBirthday
            // 
            this.NewBirthday.Location = new System.Drawing.Point(73, 85);
            this.NewBirthday.Name = "NewBirthday";
            this.NewBirthday.Size = new System.Drawing.Size(90, 29);
            this.NewBirthday.TabIndex = 7;
            // 
            // NewFirstName
            // 
            this.NewFirstName.Location = new System.Drawing.Point(73, 50);
            this.NewFirstName.Name = "NewFirstName";
            this.NewFirstName.Size = new System.Drawing.Size(90, 29);
            this.NewFirstName.TabIndex = 6;
            // 
            // NewLastName
            // 
            this.NewLastName.Location = new System.Drawing.Point(73, 15);
            this.NewLastName.Name = "NewLastName";
            this.NewLastName.Size = new System.Drawing.Size(90, 29);
            this.NewLastName.TabIndex = 5;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(14, 152);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(52, 21);
            this.label10.TabIndex = 4;
            this.label10.Text = "설명 :";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(14, 121);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(52, 21);
            this.label9.TabIndex = 3;
            this.label9.Text = "주소 :";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(14, 88);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(52, 21);
            this.label8.TabIndex = 2;
            this.label8.Text = "생일 :";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(14, 53);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(52, 21);
            this.label7.TabIndex = 1;
            this.label7.Text = "이름 :";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(14, 17);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(36, 21);
            this.label4.TabIndex = 0;
            this.label4.Text = "성 :";
            // 
            // CusListPanel
            // 
            this.CusListPanel.Controls.Add(this.CusList);
            this.CusListPanel.Location = new System.Drawing.Point(12, 27);
            this.CusListPanel.Name = "CusListPanel";
            this.CusListPanel.Size = new System.Drawing.Size(302, 373);
            this.CusListPanel.TabIndex = 11;
            // 
            // CusList
            // 
            this.CusList.AllowUserToAddRows = false;
            this.CusList.AllowUserToDeleteRows = false;
            this.CusList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.CusList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3});
            this.CusList.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.CusList.Location = new System.Drawing.Point(0, 0);
            this.CusList.MultiSelect = false;
            this.CusList.Name = "CusList";
            this.CusList.RowTemplate.Height = 25;
            this.CusList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.CusList.Size = new System.Drawing.Size(343, 373);
            this.CusList.TabIndex = 0;
            this.CusList.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.CusList_CellClick);
            // 
            // Column1
            // 
            this.Column1.HeaderText = "이름";
            this.Column1.Name = "Column1";
            // 
            // Column2
            // 
            this.Column2.HeaderText = "나이";
            this.Column2.Name = "Column2";
            // 
            // Column3
            // 
            this.Column3.HeaderText = "성인여부";
            this.Column3.Name = "Column3";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.새입양자ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(5, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(746, 24);
            this.menuStrip1.TabIndex = 12;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 새입양자ToolStripMenuItem
            // 
            this.새입양자ToolStripMenuItem.Name = "새입양자ToolStripMenuItem";
            this.새입양자ToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.새입양자ToolStripMenuItem.Text = "새 입양자";
            this.새입양자ToolStripMenuItem.Click += new System.EventHandler(this.새입양자ToolStripMenuItem_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label11.Location = new System.Drawing.Point(26, 173);
            this.label11.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(40, 25);
            this.label11.TabIndex = 16;
            this.label11.Text = "펫 :";
            // 
            // CusPetInfo
            // 
            this.CusPetInfo.AutoSize = true;
            this.CusPetInfo.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CusPetInfo.Location = new System.Drawing.Point(84, 173);
            this.CusPetInfo.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.CusPetInfo.Name = "CusPetInfo";
            this.CusPetInfo.Size = new System.Drawing.Size(60, 25);
            this.CusPetInfo.TabIndex = 20;
            this.CusPetInfo.Text = "label2";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 21F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(746, 413);
            this.Controls.Add(this.CusListPanel);
            this.Controls.Add(this.CusNewPanel);
            this.Controls.Add(this.CusDetailPanel);
            this.Controls.Add(this.menuStrip1);
            this.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.CusDetailPanel.ResumeLayout(false);
            this.CusDetailPanel.PerformLayout();
            this.CusNewPanel.ResumeLayout(false);
            this.CusNewPanel.PerformLayout();
            this.CusListPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.CusList)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button CusCreate;
        private System.Windows.Forms.Panel CusDetailPanel;
        private System.Windows.Forms.Label CusDescription;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label CusAddress;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label CusAge;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label CusFullName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label CusQualified;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel CusNewPanel;
        private System.Windows.Forms.TextBox NewDescription;
        private System.Windows.Forms.TextBox NewAddress;
        private System.Windows.Forms.TextBox NewBirthday;
        private System.Windows.Forms.TextBox NewFirstName;
        private System.Windows.Forms.TextBox NewLastName;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel CusListPanel;
        private System.Windows.Forms.DataGridView CusList;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 새입양자ToolStripMenuItem;
        private System.Windows.Forms.Label CusPetInfo;
        private System.Windows.Forms.Label label11;
    }
}

