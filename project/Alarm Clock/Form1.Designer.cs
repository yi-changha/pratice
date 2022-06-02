
namespace Alarm_Clock
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
            this.components = new System.ComponentModel.Container();
            this.panelText = new System.Windows.Forms.Label();
            this.curTime = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.CurTimeMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.AlarmMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.TimerMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.panelAlarm = new System.Windows.Forms.Panel();
            this.lbAlarmInfo = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tbMinute = new System.Windows.Forms.TextBox();
            this.tbHour = new System.Windows.Forms.TextBox();
            this.tbDay = new System.Windows.Forms.TextBox();
            this.tbSecond = new System.Windows.Forms.TextBox();
            this.tbMonth = new System.Windows.Forms.TextBox();
            this.btnSetAlarm = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            this.panelAlarm.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelText
            // 
            this.panelText.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.panelText.Cursor = System.Windows.Forms.Cursors.Default;
            this.panelText.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelText.Font = new System.Drawing.Font("휴먼편지체", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.panelText.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.panelText.Location = new System.Drawing.Point(0, 24);
            this.panelText.Name = "panelText";
            this.panelText.Size = new System.Drawing.Size(456, 134);
            this.panelText.TabIndex = 0;
            this.panelText.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // curTime
            // 
            this.curTime.Interval = 1000;
            this.curTime.Tick += new System.EventHandler(this.curTime_Tick);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.CurTimeMenu,
            this.AlarmMenu,
            this.TimerMenu});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(456, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // CurTimeMenu
            // 
            this.CurTimeMenu.Name = "CurTimeMenu";
            this.CurTimeMenu.Size = new System.Drawing.Size(71, 20);
            this.CurTimeMenu.Text = "현재 시간";
            this.CurTimeMenu.Click += new System.EventHandler(this.CurTimeMenu_Click);
            // 
            // AlarmMenu
            // 
            this.AlarmMenu.Name = "AlarmMenu";
            this.AlarmMenu.Size = new System.Drawing.Size(71, 20);
            this.AlarmMenu.Text = "알림 설정";
            this.AlarmMenu.Click += new System.EventHandler(this.AlarmMenu_Click);
            // 
            // TimerMenu
            // 
            this.TimerMenu.Name = "TimerMenu";
            this.TimerMenu.Size = new System.Drawing.Size(12, 20);
            // 
            // panelAlarm
            // 
            this.panelAlarm.BackColor = System.Drawing.SystemColors.Control;
            this.panelAlarm.Controls.Add(this.lbAlarmInfo);
            this.panelAlarm.Controls.Add(this.label6);
            this.panelAlarm.Controls.Add(this.label5);
            this.panelAlarm.Controls.Add(this.label4);
            this.panelAlarm.Controls.Add(this.label3);
            this.panelAlarm.Controls.Add(this.label2);
            this.panelAlarm.Controls.Add(this.label1);
            this.panelAlarm.Controls.Add(this.tbMinute);
            this.panelAlarm.Controls.Add(this.tbHour);
            this.panelAlarm.Controls.Add(this.tbDay);
            this.panelAlarm.Controls.Add(this.tbSecond);
            this.panelAlarm.Controls.Add(this.tbMonth);
            this.panelAlarm.Controls.Add(this.btnSetAlarm);
            this.panelAlarm.Location = new System.Drawing.Point(12, 27);
            this.panelAlarm.Name = "panelAlarm";
            this.panelAlarm.Size = new System.Drawing.Size(460, 148);
            this.panelAlarm.TabIndex = 2;
            // 
            // lbAlarmInfo
            // 
            this.lbAlarmInfo.AutoSize = true;
            this.lbAlarmInfo.Font = new System.Drawing.Font("맑은 고딕", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lbAlarmInfo.Location = new System.Drawing.Point(61, 101);
            this.lbAlarmInfo.Name = "lbAlarmInfo";
            this.lbAlarmInfo.Size = new System.Drawing.Size(45, 21);
            this.lbAlarmInfo.TabIndex = 4;
            this.lbAlarmInfo.Text = "label";
            this.lbAlarmInfo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(34, 96);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(0, 12);
            this.label6.TabIndex = 3;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label5.Location = new System.Drawing.Point(403, 35);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(22, 15);
            this.label5.TabIndex = 2;
            this.label5.Text = "초";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label4.Location = new System.Drawing.Point(323, 35);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(22, 15);
            this.label4.TabIndex = 2;
            this.label4.Text = "분";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label3.Location = new System.Drawing.Point(243, 35);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(22, 15);
            this.label3.TabIndex = 2;
            this.label3.Text = "시";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label2.Location = new System.Drawing.Point(163, 35);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(22, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "일";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(83, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(22, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "월";
            // 
            // tbMinute
            // 
            this.tbMinute.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbMinute.Location = new System.Drawing.Point(268, 30);
            this.tbMinute.Name = "tbMinute";
            this.tbMinute.Size = new System.Drawing.Size(52, 25);
            this.tbMinute.TabIndex = 1;
            // 
            // tbHour
            // 
            this.tbHour.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbHour.Location = new System.Drawing.Point(188, 30);
            this.tbHour.Name = "tbHour";
            this.tbHour.Size = new System.Drawing.Size(52, 25);
            this.tbHour.TabIndex = 1;
            // 
            // tbDay
            // 
            this.tbDay.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbDay.Location = new System.Drawing.Point(108, 30);
            this.tbDay.Name = "tbDay";
            this.tbDay.Size = new System.Drawing.Size(52, 25);
            this.tbDay.TabIndex = 1;
            // 
            // tbSecond
            // 
            this.tbSecond.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbSecond.Location = new System.Drawing.Point(348, 30);
            this.tbSecond.Name = "tbSecond";
            this.tbSecond.Size = new System.Drawing.Size(52, 25);
            this.tbSecond.TabIndex = 1;
            // 
            // tbMonth
            // 
            this.tbMonth.Font = new System.Drawing.Font("굴림", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbMonth.Location = new System.Drawing.Point(28, 30);
            this.tbMonth.Name = "tbMonth";
            this.tbMonth.Size = new System.Drawing.Size(52, 25);
            this.tbMonth.TabIndex = 1;
            // 
            // btnSetAlarm
            // 
            this.btnSetAlarm.Location = new System.Drawing.Point(348, 65);
            this.btnSetAlarm.Name = "btnSetAlarm";
            this.btnSetAlarm.Size = new System.Drawing.Size(75, 23);
            this.btnSetAlarm.TabIndex = 0;
            this.btnSetAlarm.Text = "설정";
            this.btnSetAlarm.UseVisualStyleBackColor = true;
            this.btnSetAlarm.Click += new System.EventHandler(this.btnSetAlarm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(456, 158);
            this.Controls.Add(this.panelAlarm);
            this.Controls.Add(this.panelText);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panelAlarm.ResumeLayout(false);
            this.panelAlarm.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label panelText;
        private System.Windows.Forms.Timer curTime;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem CurTimeMenu;
        private System.Windows.Forms.ToolStripMenuItem AlarmMenu;
        private System.Windows.Forms.Panel panelAlarm;
        private System.Windows.Forms.Button btnSetAlarm;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbMinute;
        private System.Windows.Forms.TextBox tbHour;
        private System.Windows.Forms.TextBox tbDay;
        private System.Windows.Forms.TextBox tbSecond;
        private System.Windows.Forms.TextBox tbMonth;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lbAlarmInfo;
        private System.Windows.Forms.ToolStripMenuItem TimerMenu;
    }
}

