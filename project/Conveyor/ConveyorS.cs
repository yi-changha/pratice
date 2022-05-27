using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conveyor
{
    class ConveyorS : CDevice   // 셔틀 컨베이어
    {
        public RPIO ConvPio1;
        public RPIO ConvPio2;
        public RPIO ConvPio3;
        public RPIO ConvPio4;

        public ConveyorS()
        {
            ConvPio1 = new RPIO();
            ConvPio2 = new RPIO();
            ConvPio3 = new RPIO();
            ConvPio4 = new RPIO();

            carrier = new Carrier();
        }

        public enum SERVO_POS
        {
            CONV_NONE = 0,
            CONV1 = 1,
            CONV2 = 2,
            CONV3 = 3,
            CONV4 = 4
        }

        private SERVO_POS tarPos;
        private SERVO_POS curPos;
        public SERVO_POS TargetPosition
        {
            get { return tarPos; }
        }
        public SERVO_POS CurrentPosition
        {
            get { return curPos; }
            set { curPos = value; }
        }
        private void MovePosition(SERVO_POS target)
        {
            tarPos = target;
        }

        public SERVO_POS GetPosition()
        {
            return curPos;
        }

        public override void Process()
        {
            if (blsAutoConv == true)
            {
                switch (stepConv)
                {
                    case 0:
                        stepConv = 100;
                        break;

                    case 100:
                        if (ConvPio1.UReq) stepConv = 200;
                        else if (ConvPio2.UReq) stepConv = 300;
                        else if (ConvPio3.UReq) stepConv = 400;
                        else if (ConvPio4.UReq) stepConv = 500;
                        break;

                    case 200:
                        if (ConvPio1.UReq)
                        {
                            MovePosition(SERVO_POS.CONV1);
                            if (GetPosition() == SERVO_POS.CONV1)
                            {
                                stepConv = 210;
                            }
                        }
                        break;

                    case 210:
                        ConvPio1.TrReq = true;
                        if (ConvPio1.UReq && ConvPio1.Ready)
                        {
                            stepConv = 220;
                        }
                        break;

                    case 220:
                        statusCcwConv = true;
                        ConvPio1.Busy = true;
                        if (ConvPio1.Ready && blsSensorDetect1)
                        {
                            statusCcwConv = false;
                            ConvPio1.TrReq = false;
                            ConvPio1.Busy = false;
                            stepConv = 230;
                        }
                        break;

                    case 230:
                        ConvPio1.Compt = true;
                        if (!ConvPio1.Ready)
                        {
                            ConvPio1.Compt = false;
                            stepConv = 240;
                        }
                        break;

                    case 240:
                        stepConv = 600;
                        break;

                    case 300:
                        if (ConvPio2.UReq)
                        {
                            MovePosition(SERVO_POS.CONV2);
                            if (GetPosition() == SERVO_POS.CONV2)
                            {
                                stepConv = 310;
                            }
                        }
                        break;

                    case 310:
                        ConvPio2.TrReq = true;
                        if (ConvPio2.UReq && ConvPio2.Ready)
                        {
                            stepConv = 320;
                        }
                        break;

                    case 320:
                        statusCcwConv = true;
                        ConvPio2.Busy = true;
                        if (ConvPio2.Ready && blsSensorDetect2)
                        {
                            statusCcwConv = false;
                            ConvPio2.TrReq = false;
                            ConvPio2.Busy = false;
                            stepConv = 330;
                        }
                        break;

                    case 330:
                        ConvPio2.Compt = true;
                        if (!ConvPio2.Ready)
                        {
                            ConvPio2.Compt = false;
                            stepConv = 340;
                        }
                        break;

                    case 340:
                        stepConv = 600;
                        break;

                    case 400:
                        if (ConvPio3.UReq)
                        {
                            MovePosition(SERVO_POS.CONV3);
                            if (GetPosition() == SERVO_POS.CONV3)
                            {
                                stepConv = 410;
                            }
                        }
                        break;

                    case 410:
                        ConvPio3.TrReq = true;
                        if (ConvPio3.UReq && ConvPio3.Ready)
                        {
                            stepConv = 420;
                        }
                        break;

                    case 420:
                        statusCwConv = true;
                        ConvPio3.Busy = true;
                        if (ConvPio3.Ready && blsSensorDetect2)
                        {
                            statusCwConv = false;
                            ConvPio3.TrReq = false;
                            ConvPio3.Busy = false;
                            stepConv = 430;
                        }
                        break;

                    case 430:
                        ConvPio3.Compt = true;
                        if (!ConvPio3.Ready)
                        {
                            ConvPio3.Compt = false;
                            stepConv = 440;
                        }
                        break;

                    case 440:
                        stepConv = 600;
                        break;

                    case 500:
                        if (ConvPio4.UReq)
                        {
                            MovePosition(SERVO_POS.CONV4);
                            if (GetPosition() == SERVO_POS.CONV4)
                            {
                                stepConv = 510;
                            }
                        }
                        break;

                    case 510:
                        ConvPio4.TrReq = true;
                        if (ConvPio4.UReq && ConvPio4.Ready)
                        {
                            stepConv = 520;
                        }
                        break;

                    case 520:
                        statusCwConv = true;
                        ConvPio4.Busy = true;
                        if (ConvPio4.Ready && blsSensorDetect1)
                        {
                            statusCwConv = false;
                            ConvPio4.TrReq = false;
                            ConvPio4.Busy = false;
                            stepConv = 530;
                        }
                        break;

                    case 530:
                        ConvPio4.Compt = true;
                        if (!ConvPio4.Ready)
                        {
                            ConvPio4.Compt = false;
                            stepConv = 540;
                        }
                        break;

                    case 540:
                        stepConv = 600;
                        break;

                    case 600:
                        if (carrier.id != 0)
                        {
                            if (carrier.use == Carrier.USE.USE_TAKEOUT)
                            {
                                if (ConvPio1.LReq)
                                {
                                    stepConv = 700;
                                    carrier.dest = 1;
                                }
                            }
                            else if (carrier.use == Carrier.USE.USE_STACK)
                            {
                                if (ConvPio3.LReq)
                                {
                                    stepConv = 900;
                                    carrier.dest = 3;
                                }    
                                if (ConvPio4.LReq)
                                {
                                    stepConv = 1000;
                                    carrier.dest = 4;
                                }
                            }
                            else if (carrier.use == Carrier.USE.USE_NONE)
                            {
                                // 에러 처리
                                if (ConvPio1.LReq)
                                {
                                    stepConv = 700;
                                    carrier.dest = 1;
                                }
                            }
                        }
                        else
                        {

                        }
                        break;

                    case 700:
                        if (ConvPio1.LReq)
                        {
                            MovePosition(SERVO_POS.CONV1);
                            if (GetPosition() == SERVO_POS.CONV1)
                                stepConv = 710;
                        }
                        break;

                    case 710:
                        ConvPio1.TrReq = true;
                        if (ConvPio1.LReq && ConvPio1.Ready)
                        {
                            stepConv = 720;
                        }
                        break;

                    case 720:
                        statusCwConv = true;
                        ConvPio1.Busy = true;
                        if (!blsSensorDetect1 && !blsSensorDetect2)
                        {
                            statusCwConv = false;
                            ConvPio1.TrReq = false;
                            ConvPio1.Busy = false;
                            stepConv = 730;
                        }
                        break;

                    case 730:
                        ConvPio1.Compt = true;
                        if (!ConvPio1.Ready)
                        {
                            ConvPio1.Compt = false;
                            stepConv = 100;
                        }
                        break;

                    case 800:
                        if (ConvPio2.LReq)
                        {
                            MovePosition(SERVO_POS.CONV2);
                            if (GetPosition() == SERVO_POS.CONV2)
                                stepConv = 810;
                        }
                        break;

                    case 810:
                        ConvPio2.TrReq = true;
                        if (ConvPio2.LReq && ConvPio2.Ready)
                        {
                            stepConv = 820;
                        }
                        break;

                    case 820:
                        statusCwConv = true;
                        ConvPio2.Busy = true;
                        if (!blsSensorDetect1 && !blsSensorDetect2)
                        {
                            statusCwConv = false;
                            ConvPio2.TrReq = false;
                            ConvPio2.Busy = false;
                            stepConv = 830;
                        }
                        break;

                    case 830:
                        ConvPio2.Compt = true;
                        if (!ConvPio2.Ready)
                        {
                            ConvPio2.Compt = false;
                            stepConv = 100;
                        }
                        break;

                    case 900:
                        if (ConvPio3.LReq)
                        {
                            MovePosition(SERVO_POS.CONV3);
                            if (GetPosition() == SERVO_POS.CONV3)
                                stepConv = 910;
                        }
                        break;

                    case 910:
                        ConvPio3.TrReq = true;
                        if (ConvPio3.LReq && ConvPio3.Ready)
                        {
                            stepConv = 920;
                        }
                        break;

                    case 920:
                        statusCcwConv = true;
                        ConvPio3.Busy = true;
                        if (!blsSensorDetect1 && !blsSensorDetect2)
                        {
                            statusCcwConv = false;
                            ConvPio3.TrReq = false;
                            ConvPio3.Busy = false;
                            stepConv = 930;
                        }
                        break;

                    case 930:
                        ConvPio3.Compt = true;
                        if (!ConvPio3.Ready)
                        {
                            ConvPio3.Compt = false;
                            stepConv = 100;
                        }
                        break;

                    case 1000:
                        if (ConvPio4.LReq)
                        {
                            MovePosition(SERVO_POS.CONV4);
                            if (GetPosition() == SERVO_POS.CONV4)
                                stepConv = 1010;
                        }
                        break;

                    case 1010:
                        ConvPio4.TrReq = true;
                        if (ConvPio4.LReq && ConvPio4.Ready)
                        {
                            stepConv = 1020;
                        }
                        break;

                    case 1020:
                        statusCcwConv = true;
                        ConvPio4.Busy = true;
                        if (!blsSensorDetect1 && !blsSensorDetect2)
                        {
                            statusCcwConv = false;
                            ConvPio4.TrReq = false;
                            ConvPio4.Busy = false;
                            stepConv = 1030;
                        }
                        break;

                    case 1030:
                        ConvPio4.Compt = true;
                        if (!ConvPio4.Ready)
                        {
                            ConvPio4.Compt = false;
                            stepConv = 100;
                        }
                        break;

                    default:
                        stepConv = 0;
                        break;
                }
            }
            else
            {
                stepConv = 0;
            }
            if (oldStepConv != stepConv)
            {
                Console.WriteLine("Shuttle Conveyor Step = {0}", stepConv);
            }
            oldStepConv = stepConv;
            blsTakeIn = false;  // 입고된 것 사용 완료
        }
    }
}
