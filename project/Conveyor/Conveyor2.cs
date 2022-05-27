using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conveyor
{
    class Conveyor2 : CDevice
    {
        public Conveyor2()
        {
            carrier = new Carrier();
        }

        public override void Process()
        {
            if (blsAutoConv == true)   // 자동 ON 상태
            {
                switch (stepConv)
                {
                    case 0:
                        blsUReq = false;
                        blsLReq = false;
                        blsReady = false;
                        statusCwConv = false;
                        statusCcwConv = false;

                        stepConv = 100;
                        break;

                    case 100:
                        if (blsSensorDetect2 == true)   // 자재 감지 시 200번으로 이동
                        {
                            stepConv = 200;
                        }
                        else     // 자재가 감지되지 않으면 대기
                        {
                            if (blsTakeIn == true)  // 입고 버튼을 누르면 110번 스텝으로 이동
                            {
                                stepConv = 110;
                                countConv = 0;
                            }
                        }
                        break;

                    case 110:
                        statusCcwConv = true;      // 모터 구동, 컨베이어 가동
                        if (blsSensorDetect2 == true)    //센서가 감지되면 200번 스탭으로 이동
                        {
                            statusCcwConv = false;
                            blsUReq = true;
                            stepConv = 200;
                        }
                        break;

                    case 200:
                        if (blsSensorDetect2 == false)
                        {
                            stepConv = 100;
                        }
                        else if (blsTrReq) // 이동 요청이 발생하면, 210번 스텝으로 이동, Ready On
                        {
                            stepConv = 210;
                            blsReady = true;
                        }
                        break;

                    case 210:
                        if (blsBusy)   // Busy On이면, 이동요청 On, 220번 스텝으로 이동
                        {
                            blsUReq = true;
                            stepConv = 220;
                        }
                        break;

                    case 220:
                        statusCcwConv = true;  // 컨베이어 반시계 방향 On
                        if (!blsTrReq && !blsBusy && blsCompt)
                        {
                            blsUReq = false;
                            blsReady = false;
                            statusCcwConv = false;
                            stepConv = 230;
                        }
                        break;

                    case 230:
                        if (!blsCompt) // 완료가 꺼졌는지 보고 100번으로 이동
                            stepConv = 100;
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
                Console.WriteLine("Conveyor 2 Step = {0}", stepConv);
            }
            oldStepConv = stepConv;
            blsTakeIn = false;  // 입고된 것 사용 완료
        }
    }
}
