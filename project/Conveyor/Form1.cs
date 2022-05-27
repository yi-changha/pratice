using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Conveyor
{
    public partial class Form1 : Form
    {
        bool blsSimulatorMode = true;
        bool ConvMotionBlink;
        Conveyor1 conveyor1;
        Conveyor2 conveyor2;
        Conveyor3 conveyor3;
        Conveyor4 conveyor4;
        ConveyorS conveyorS;
        public Form1()
        {
            InitializeComponent();
            conveyor1 = new Conveyor1();
            conveyor2 = new Conveyor2();
            conveyor3 = new Conveyor3();
            conveyor4 = new Conveyor4();
            conveyorS = new ConveyorS();
        }

        private void btnTakein_Click(object sender, EventArgs e)
        {
            if(conveyor2.carrier.id == 0)
            {
                conveyor2.carrier.id = 1;
                conveyor2.carrier.source = 2;
                conveyor2.carrier.use = Carrier.USE.USE_STACK;

                conveyor2.takein = true;

                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("Input Button Clicked...");
                Console.ResetColor();
            }
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            conveyor1.auto = false;
            conveyor2.auto = false;
            conveyor3.auto = false;
            conveyor4.auto = false;
            conveyorS.auto = false;
        }
        private void btnTakeout_Click(object sender, EventArgs e)   // 반출할 수 있는 컨베이어는 3,4
        {
            if (selectedConv == CONV_TYPE.CONV3)
            {
                if (conveyor3.carrier.id != 0)
                {
                    conveyor3.carrier.use = Carrier.USE.USE_TAKEOUT;
                }
            }
            if (selectedConv == CONV_TYPE.CONV4)
            {
                if (conveyor4.carrier.id != 0)
                {
                    conveyor4.carrier.use = Carrier.USE.USE_TAKEOUT;
                }
            }
        }
        private void btnAuto_Click(object sender, EventArgs e)
        {
            conveyor1.auto = true;
            conveyor2.auto = true;
            conveyor3.auto = true;
            conveyor4.auto = true;
            conveyorS.auto = true;
        }
        private void ConvMotionProc_Tick(object sender, EventArgs e)
        {
            if (ConvMotionBlink == true)
            {
                btnConveyor1.Text = "";
                btnConveyor2.Text = "";
                btnConveyor3.Text = "";
                btnConveyor4.Text = "";
                btnConveyorS.Text = "";

                ConvMotionBlink = false;
            }
            else
            {
                if (!conveyor1.statusCw && !conveyor1.statusCcw) btnConveyor1.Text = "";  // 시계방향, 반시계 방향 모두 아니면 None
                else if (conveyor1.statusCw) btnConveyor1.Text = "CW";               // 시계방향이면 CW로 표시
                else if (conveyor1.statusCcw) btnConveyor1.Text = "CCW";             // 반시계방향이면 CCW로 표시
                if (!conveyor2.statusCw && !conveyor2.statusCcw) btnConveyor2.Text = "";  // 시계방향, 반시계 방향 모두 아니면 None
                else if (conveyor2.statusCw) btnConveyor2.Text = "CW";               // 시계방향이면 CW로 표시
                else if (conveyor2.statusCcw) btnConveyor2.Text = "CCW";
                if (!conveyor3.statusCw && !conveyor3.statusCcw) btnConveyor3.Text = "";  // 시계방향, 반시계 방향 모두 아니면 None
                else if (conveyor3.statusCw) btnConveyor3.Text = "CW";               // 시계방향이면 CW로 표시
                else if (conveyor3.statusCcw) btnConveyor3.Text = "CCW";
                if (!conveyor4.statusCw && !conveyor4.statusCcw) btnConveyor4.Text = "";  // 시계방향, 반시계 방향 모두 아니면 None
                else if (conveyor4.statusCw) btnConveyor4.Text = "CW";               // 시계방향이면 CW로 표시
                else if (conveyor4.statusCcw) btnConveyor4.Text = "CCW";
                if (!conveyorS.statusCw && !conveyorS.statusCcw) btnConveyorS.Text = "";  // 시계방향, 반시계 방향 모두 아니면 None
                else if (conveyorS.statusCw) btnConveyorS.Text = "CW";               // 시계방향이면 CW로 표시
                else if (conveyorS.statusCcw) btnConveyorS.Text = "CCW";

                ConvMotionBlink = true;
            }
        }
        private void MainSchedulerProc_Tick(object sender, EventArgs e)
        {
            conveyor1.Process();
            conveyor2.Process();
            conveyor3.Process();
            conveyor4.Process();
            conveyorS.Process();

            PioExchanger();
            DataExchanger();
            MotionControl();
            Simulator();
        }
        private void DataExchanger()
        {
            if (conveyor1.Compt)
            {
                if (conveyor1.LReq)
                {
                    if (conveyorS.carrier.id != 0)
                    {
                        conveyor1.carrier.id = conveyorS.carrier.id;
                        conveyor1.carrier.source = conveyorS.carrier.source;
                        conveyor1.carrier.dest = conveyorS.carrier.dest;
                        conveyor1.carrier.use = conveyorS.carrier.use;
                        conveyorS.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : S -> 1");
                    }
                }
                if (conveyor1.UReq)
                {
                    if (conveyor1.carrier.id != 0)
                    {
                        conveyorS.carrier.id = conveyor1.carrier.id;
                        conveyorS.carrier.source = conveyor1.carrier.source;
                        conveyorS.carrier.dest = conveyor1.carrier.dest;
                        conveyorS.carrier.use = conveyor1.carrier.use;
                        conveyor1.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : 1 -> S");
                    }
                }
            }
            if (conveyor2.Compt)
            {
                if (conveyor2.LReq)
                {
                    if (conveyorS.carrier.id != 0)
                    {
                        conveyor2.carrier.id = conveyorS.carrier.id;
                        conveyor2.carrier.source = conveyorS.carrier.source;
                        conveyor2.carrier.dest = conveyorS.carrier.dest;
                        conveyor2.carrier.use = conveyorS.carrier.use;
                        conveyorS.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : S -> 2");
                    }
                }
                if (conveyor2.UReq)
                {
                    if (conveyor2.carrier.id != 0)
                    {
                        conveyorS.carrier.id = conveyor2.carrier.id;
                        conveyorS.carrier.source = conveyor2.carrier.source;
                        conveyorS.carrier.dest = conveyor2.carrier.dest;
                        conveyorS.carrier.use = conveyor2.carrier.use;
                        conveyor2.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : 2 -> S");
                    }
                }
            }
            if (conveyor3.Compt)
            {
                if (conveyor3.LReq)
                {
                    if (conveyorS.carrier.id != 0)
                    {
                        conveyor3.carrier.id = conveyorS.carrier.id;
                        conveyor3.carrier.source = conveyorS.carrier.source;
                        conveyor3.carrier.dest = conveyorS.carrier.dest;
                        conveyor3.carrier.use = conveyorS.carrier.use;
                        conveyorS.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : S -> 3");
                    }
                }
                if (conveyor3.UReq)
                {
                    if (conveyor3.carrier.id != 0)
                    {
                        conveyorS.carrier.id = conveyor3.carrier.id;
                        conveyorS.carrier.source = conveyor3.carrier.source;
                        conveyorS.carrier.dest = conveyor3.carrier.dest;
                        conveyorS.carrier.use = conveyor3.carrier.use;
                        conveyor3.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : 3 -> S");
                    }
                }
            }
            if (conveyor4.Compt)
            {
                if (conveyor4.LReq)
                {
                    if (conveyorS.carrier.id != 0)
                    {
                        conveyor4.carrier.id = conveyorS.carrier.id;
                        conveyor4.carrier.source = conveyorS.carrier.source;
                        conveyor4.carrier.dest = conveyorS.carrier.dest;
                        conveyor4.carrier.use = conveyorS.carrier.use;
                        conveyorS.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : S -> 4");
                    }
                }
                if (conveyor4.UReq)
                {
                    if (conveyor4.carrier.id != 0)
                    {
                        conveyorS.carrier.id = conveyor4.carrier.id;
                        conveyorS.carrier.source = conveyor4.carrier.source;
                        conveyorS.carrier.dest = conveyor4.carrier.dest;
                        conveyorS.carrier.use = conveyor4.carrier.use;
                        conveyor4.carrier.Clear();

                        Console.WriteLine("Carrier Data Move : 4 -> S");
                    }
                }
            }
        }
        private void MotionControl()
        {
            switch(conveyorS.TargetPosition)
            {
                case ConveyorS.SERVO_POS.CONV_NONE:
                    btnConveyorS.Location = new System.Drawing.Point(230, 160);
                    cbSensorS_2.Location = new System.Drawing.Point(170, 160);
                    cbSensorS_1.Location = new System.Drawing.Point(170, 240);
                    break;
                case ConveyorS.SERVO_POS.CONV1:
                    btnConveyorS.Location = new System.Drawing.Point(100, 160);
                    cbSensorS_2.Location = new System.Drawing.Point(40, 160);
                    cbSensorS_1.Location = new System.Drawing.Point(40, 240);
                    break;
                case ConveyorS.SERVO_POS.CONV2:
                    btnConveyorS.Location = new System.Drawing.Point(360, 160);
                    cbSensorS_2.Location = new System.Drawing.Point(300, 160);
                    cbSensorS_1.Location = new System.Drawing.Point(300, 240);
                    break;
                case ConveyorS.SERVO_POS.CONV3:
                    btnConveyorS.Location = new System.Drawing.Point(360, 160);
                    cbSensorS_2.Location = new System.Drawing.Point(40, 160);
                    cbSensorS_1.Location = new System.Drawing.Point(40, 240);
                    break;
                case ConveyorS.SERVO_POS.CONV4:
                    btnConveyorS.Location = new System.Drawing.Point(360, 160);
                    cbSensorS_2.Location = new System.Drawing.Point(300, 160);
                    cbSensorS_1.Location = new System.Drawing.Point(300, 240);
                    break;
                default:
                    btnConveyorS.Location = new System.Drawing.Point(230, 160);
                    cbSensorS_2.Location = new System.Drawing.Point(170, 160);
                    cbSensorS_1.Location = new System.Drawing.Point(170, 240);
                    break;
            }
            conveyorS.CurrentPosition = conveyorS.TargetPosition;
        }
        private void PioExchanger()
        {
            conveyor1.TrReq = conveyorS.ConvPio1.TrReq;
            conveyor1.Busy = conveyorS.ConvPio1.Busy;
            conveyor1.Compt = conveyorS.ConvPio1.Compt;
            conveyorS.ConvPio1.LReq = conveyor1.LReq;
            conveyorS.ConvPio1.UReq = conveyor1.UReq;
            conveyorS.ConvPio1.Ready = conveyor1.Ready;

            conveyor2.TrReq = conveyorS.ConvPio2.TrReq;
            conveyor2.Busy = conveyorS.ConvPio2.Busy;
            conveyor2.Compt = conveyorS.ConvPio2.Compt;
            conveyorS.ConvPio2.LReq = conveyor2.LReq;
            conveyorS.ConvPio2.UReq = conveyor2.UReq;
            conveyorS.ConvPio2.Ready = conveyor2.Ready;

            conveyor3.TrReq = conveyorS.ConvPio3.TrReq;
            conveyor3.Busy = conveyorS.ConvPio3.Busy;
            conveyor3.Compt = conveyorS.ConvPio3.Compt;
            conveyorS.ConvPio3.LReq = conveyor3.LReq;
            conveyorS.ConvPio3.UReq = conveyor3.UReq;
            conveyorS.ConvPio3.Ready = conveyor3.Ready;

            conveyor4.TrReq = conveyorS.ConvPio4.TrReq;
            conveyor4.Busy = conveyorS.ConvPio4.Busy;
            conveyor4.Compt = conveyorS.ConvPio4.Compt;
            conveyorS.ConvPio4.LReq = conveyor4.LReq;
            conveyorS.ConvPio4.UReq = conveyor4.UReq;
            conveyorS.ConvPio4.Ready = conveyor4.Ready;
        }

        UInt16[] ConvTimer = new UInt16[5];
        private void Simulator()
        {
            if (blsSimulatorMode)
            {
                if (conveyor2.carrier.id != 0 && conveyor2.statusCw)
                {
                    ConvTimer[0]++;
                    if (ConvTimer[0] > 5)
                    {
                        cbSensor1_1.Checked = true;
                        ConvTimer[0] = 0;
                    }
                }
                else
                {
                    if (conveyor1.carrier.id == 0)
                    {
                        cbSensor1_1.Checked = false;
                        cbSensor1_2.Checked = false;
                    }
                    ConvTimer[0] = 0;
                }
                
                if (conveyor2.carrier.id != 0 && conveyor2.statusCcw)
                {
                    ConvTimer[1]++;
                    if (ConvTimer[1] > 5)
                    {
                        cbSensor2_2.Checked = true;
                        ConvTimer[1] = 0;
                    }
                }
                else
                {
                    if (conveyor2.carrier.id == 0)
                    {
                        cbSensor2_2.Checked = false;
                    }
                    ConvTimer[1] = 0;
                }

                if (conveyor3.carrier.id != 0 && conveyor3.statusCcw)
                {
                    ConvTimer[2]++;
                    if (ConvTimer[2] > 5)
                    {
                        cbSensor3_2.Checked = true;
                        ConvTimer[2] = 0;
                    }
                }
                else
                {
                    if (conveyor3.carrier.id == 0)
                    {
                        cbSensor3_2.Checked = false;
                    }
                    ConvTimer[2] = 0;
                }


                if (conveyor4.carrier.id != 0 && conveyor4.statusCcw)
                {
                    ConvTimer[3]++;
                    if(ConvTimer[3] > 5)
                    {
                        cbSensor4_2.Checked = true;
                        ConvTimer[3] = 0;
                    }
                }
                else
                {
                    if (conveyor4.carrier.id == 0)
                    {
                        cbSensor4_2.Checked = false;
                    }
                    ConvTimer[3] = 0;
                }

                if (conveyorS.carrier.id == 0)
                {
                    if (conveyorS.statusCcw)
                    {
                        ConvTimer[4]++;
                        if (ConvTimer[4] > 5)
                        {
                            cbSensorS_2.Checked = true;
                            ConvTimer[4] = 0;
                        }
                    }
                    else if (conveyorS.statusCw)
                    {
                        ConvTimer[4]++;
                        if (ConvTimer[4] > 5)
                        {
                            cbSensorS_1.Checked = true;
                            ConvTimer[4] = 0;
                        }
                    }
                }
                else
                {
                    if (conveyorS.statusCcw || conveyorS.statusCw)
                    {
                        ConvTimer[4]++;
                        if (ConvTimer[4] > 5)
                        {
                            cbSensorS_1.Checked = false;
                            cbSensorS_2.Checked = false;
                        }
                    }
                }
            }
        }

        private void cbSensor1_1_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor1_1.Checked)
                conveyor1.sensor1 = true;
            else
                conveyor1.sensor1 = false;
        }
        private void cbSensor1_2_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor1_2.Checked)
                conveyor1.sensor2 = true;
            else
                conveyor1.sensor2 = false;
        }
        private void cbSensor2_1_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor2_1.Checked)
                conveyor2.sensor1 = true;
            else
                conveyor2.sensor1 = false;
        }
        private void cbSensor2_2_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor2_2.Checked)
                conveyor2.sensor2 = true;
            else
                conveyor2.sensor2 = false;
        }
        private void cbSensor3_1_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor3_1.Checked)
                conveyor3.sensor1 = true;
            else
                conveyor3.sensor1 = false;
        }
        private void cbSensor3_2_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor3_2.Checked)
                conveyor3.sensor2 = true;
            else
                conveyor3.sensor2 = false;
        }
        private void cbSensor4_1_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor4_1.Checked)
                conveyor4.sensor1 = true;
            else
                conveyor4.sensor1 = false;
        }
        private void cbSensor4_2_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensor4_2.Checked)
                conveyor4.sensor2 = true;
            else
                conveyor4.sensor2 = false;
        }
        private void cbSensorS_1_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensorS_1.Checked)
                conveyorS.sensor1 = true;
            else
                conveyorS.sensor1 = false;
        }
        private void cbSensorS_2_CheckedChanged(object sender, EventArgs e)
        {
            if (cbSensorS_2.Checked)
                conveyorS.sensor2 = true;
            else
                conveyorS.sensor2 = false;
        }


        private enum CONV_TYPE
        {
            CONV_NONE,
            CONV1,
            CONV2,
            CONV3,
            CONV4,
            CONVS
        }
        private CONV_TYPE selectedConv;

        private void SelectConv(CONV_TYPE select)
        {
            btnConveyor1.BackColor = System.Drawing.Color.LightGreen;
            btnConveyor2.BackColor = System.Drawing.Color.LightGreen;
            btnConveyor3.BackColor = System.Drawing.Color.LightGreen;
            btnConveyor4.BackColor = System.Drawing.Color.LightGreen;
            btnConveyorS.BackColor = System.Drawing.Color.LightGreen;
            if (select == CONV_TYPE.CONV1) btnConveyor1.BackColor = System.Drawing.Color.Azure;
            if (select == CONV_TYPE.CONV2) btnConveyor2.BackColor = System.Drawing.Color.Azure;
            if (select == CONV_TYPE.CONV3) btnConveyor3.BackColor = System.Drawing.Color.Azure;
            if (select == CONV_TYPE.CONV4) btnConveyor4.BackColor = System.Drawing.Color.Azure;
            if (select == CONV_TYPE.CONVS) btnConveyorS.BackColor = System.Drawing.Color.Azure;
        }

        private void btnConveyor1_Click(object sender, EventArgs e)
        {
            selectedConv = CONV_TYPE.CONV1;
            SelectConv(selectedConv);
        }

        private void btnConveyor2_Click(object sender, EventArgs e)
        {
            selectedConv = CONV_TYPE.CONV2;
            SelectConv(selectedConv);
        }

        private void btnConveyor3_Click(object sender, EventArgs e)
        {
            selectedConv = CONV_TYPE.CONV3;
            SelectConv(selectedConv);
        }

        private void btnConveyor4_Click(object sender, EventArgs e)
        {
            selectedConv = CONV_TYPE.CONV4;
            SelectConv(selectedConv);
        }

        private void btnConveyorS_Click(object sender, EventArgs e)
        {
            selectedConv = CONV_TYPE.CONVS;
            SelectConv(selectedConv);
        }
    }
}
