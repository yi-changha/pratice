using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conveyor
{
    abstract class CDevice : IProcess
    {
        protected bool blsTrReq;   // Transfer Request 상태, Shuttle Conveyor
        protected bool blsBusy;
        protected bool blsCompt;   // 모든 동작 완료
        protected bool blsUReq;    // Unload Request 상태, Conveyor
        protected bool blsLReq;    // Load Request 상태, Conveyor
        protected bool blsReady;   // Ready 상태, Conveyor

        public Carrier carrier;

        public bool TrReq
        {
            get { return blsTrReq; }
            set { blsTrReq = value; }
        }
        public bool Busy
        {
            get { return blsBusy; }
            set { blsBusy = value; }
        }
        public bool Compt
        {
            get { return blsCompt; }
            set { blsCompt = value; }
        }
        public bool UReq
        {
            get { return blsUReq; }
        }
        public bool LReq
        {
            get { return blsLReq; }
        }
        public bool Ready
        {
            get { return blsReady; }
        }

        protected bool statusCwConv;  // 모터 회전방향 : 시계방향
        protected bool statusCcwConv;    // 모터 회전방향 : 반시계 방향
        public bool statusCw
        {
            get { return statusCwConv; }
            set { statusCwConv = value; }
        }
        public bool statusCcw
        {
            get { return statusCcwConv; }
            set { statusCcwConv = value; }
        }

        protected int stepConv;
        protected int oldStepConv;
        protected int countConv;
        public int step
        {
            get { return stepConv; }
            set { stepConv = value; }
        }
        public int oldStep
        {
            get { return oldStepConv; }
            set { oldStepConv = value; }
        }
        public int count
        {
            get { return countConv; }
            set { countConv = value; }
        }

        protected bool blsAutoConv;  // 자동 On/Off 상태
        protected bool blsTakeIn, blsTakeOut; // 입고, 출고 On/Off 상태
        public bool auto
        {
            get { return blsAutoConv; }
            set { blsAutoConv = value; }
        }
        public bool takein
        {
            get { return blsTakeIn; }
            set { blsTakeIn = value; }
        }
        public bool takeout
        {
            get { return blsTakeOut; }
            set { blsTakeOut = value; }
        }

        public abstract void Process();

        protected bool blsSensorDetect1, blsSensorDetect2;
        public bool sensor1
        {
            get { return blsSensorDetect1; }
            set { blsSensorDetect1 = value; }
        }
        public bool sensor2
        {
            get { return blsSensorDetect2; }
            set { blsSensorDetect2 = value; }
        }
    }
}
