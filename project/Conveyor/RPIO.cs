using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conveyor
{
    class RPIO
    {
        private bool blsTrReq;   // Transfer Request 상태, Shuttle Conveyor
        private bool blsBusy;
        private bool blsCompt;   // 모든 동작 완료
        private bool blsUReq;    // Unload Request 상태, Conveyor
        private bool blsLReq;    // Load Request 상태, Conveyor
        private bool blsReady;   // Ready 상태, Conveyor
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
            set { blsUReq = value; }
        }
        public bool LReq
        {
            get { return blsLReq; }
            set { blsLReq = value; }
        }
        public bool Ready
        {
            get { return blsReady; }
            set { blsReady = value; }
        }
    }
}
