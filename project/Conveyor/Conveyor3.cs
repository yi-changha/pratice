using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conveyor
{
    class Conveyor3 : CDevice
    {
        public Conveyor3()
        {
            carrier = new Carrier();
        }

        public override void Process()
        {
            if (blsAutoConv == true)
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
                        blsLReq = true;
                        if (blsTrReq)
                        {
                            statusCwConv = true;
                            blsReady = true;
                            stepConv = 110;
                        }
                        break;

                    case 110:
                        if (blsBusy)
                        {
                            stepConv = 120;
                        }
                        break;

                    case 120:
                        if (blsSensorDetect2)
                        {
                            statusCwConv = false;
                            stepConv = 130;
                        }
                        break;

                    case 130:
                        if (!blsTrReq && !blsBusy && blsCompt)
                        {
                            blsLReq = false;
                            blsReady = false;
                            stepConv = 140;
                        }
                        break;

                    case 140:
                        if (!blsCompt)
                        {
                            stepConv = 200;
                        }
                        break;

                    case 200:
                        if (carrier.use == Carrier.USE.USE_TAKEOUT)
                        {
                            blsUReq = true;
                        }
                        if (blsSensorDetect2 == false)
                        {
                            stepConv = 100;
                        }
                        else if (blsTrReq)
                        {
                            stepConv = 210;
                            blsReady = true;
                        }
                        break;

                    case 210:
                        if (blsBusy) 
                        {
                            blsUReq = true;
                            stepConv = 220;
                        }
                        break;

                    case 220:
                        statusCwConv = true; 
                        if (!blsTrReq && !blsBusy && blsCompt)
                        {
                            blsUReq = false;
                            blsReady = false;
                            statusCwConv = false;
                            stepConv = 230;
                        }
                        break;

                    case 230:
                        if (!blsCompt)
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
                Console.WriteLine("Conveyor 3 Step = {0}", stepConv);
            }
            oldStepConv = stepConv;
            blsTakeIn = false;  // 입고된 것 사용 완료
        }
    }
}
