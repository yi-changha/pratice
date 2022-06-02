using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//using System.Media;   // 소리 재생

namespace Alarm_Clock
{
    public partial class Form1 : Form
    {
        public int alarmMonth, alarmDay, alarmHour, alarmMinute, alarmSecond;

        // 메뉴, 창 설정
        private void CurTimeMenu_Click(object sender, EventArgs e)
        {
            panelAlarm.Hide();
            panelText.Show();
        }
        private void AlarmMenu_Click(object sender, EventArgs e)
        {
            panelAlarm.Show();
            panelText.Hide();
            panelAlarm.Dock = DockStyle.Fill;
            lbAlarmInfo.ForeColor = Color.Black;
            lbAlarmInfo.Text = "원하는 시간을 입력 후 '설정' 버튼을 누르세요";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            panelAlarm.Hide();
            panelAlarm.Dock = DockStyle.Fill;
        }


        // 실행
        public Form1()
        {
            InitializeComponent();
            curTime.Enabled = true;
            curTime.Tick += curTime_Tick; 
        }
        private void curTime_Tick(object sender, EventArgs e)
        {
            panelText.Text = DateTime.Now.ToString();
            if (DateTime.Now.Month == alarmMonth && DateTime.Now.Day == alarmDay &&
                DateTime.Now.Hour == alarmHour && DateTime.Now.Minute == alarmMinute &&
                DateTime.Now.Second == alarmSecond)
            {
                Alarm();
            }
        }

        // 알람설정
        private void btnSetAlarm_Click(object sender, EventArgs e)
        {
            if (tbMonth.Text == string.Empty && tbDay.Text == string.Empty &&
                tbHour.Text == string.Empty && tbMinute.Text == string.Empty &&
                tbSecond.Text == string.Empty)
            {
                MessageBox.Show("숫자를 입력하세요", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            else
            {
                try
                {
                    if (tbMonth.Text != string.Empty)
                    {
                        alarmMonth = int.Parse(tbMonth.Text);
                    }
                    else
                    {
                        alarmMonth = DateTime.Now.Month;
                    }

                    if (tbDay.Text != string.Empty)
                    {
                        alarmDay = int.Parse(tbDay.Text);
                    }
                    else
                    {
                        alarmDay = DateTime.Now.Day;
                    }

                    if (tbHour.Text != string.Empty)
                    {
                        alarmHour = int.Parse(tbHour.Text);
                    }
                    else
                    {
                        alarmHour = DateTime.Now.Hour;
                    }

                    if (tbMinute.Text != string.Empty)
                    {
                        alarmMinute = int.Parse(tbMinute.Text);
                    }
                    else
                    {
                        alarmMinute = DateTime.Now.Minute;
                    }

                    if (tbSecond.Text != string.Empty)
                    {
                        alarmSecond = int.Parse(tbSecond.Text);
                    }
                    else
                    {
                        alarmSecond = DateTime.Now.Second + 1;
                    }
                    lbAlarmInfo.ForeColor = Color.Red;
                    lbAlarmInfo.Text = alarmMonth + "월 " + alarmDay + "일 " + alarmHour + "시 "
                        + alarmMinute + "분 " + alarmSecond + "초로 설정되었습니다." ;
                }
                catch
                {
                    MessageBox.Show("자연수를 입력하세요", "오류", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
        private void Alarm()
        {
            MessageBox.Show("알람시간입니다.");

            //// 소리재생
            //SoundPlayer sound = new SoundPlayer(""); // "" 안에 디렉토리 입력
            //sound.Play();
        }
    }
}
