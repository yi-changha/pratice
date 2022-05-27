using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conveyor
{
    class Carrier
    {
        public UInt64 id;
        public UInt16 source;   // 출발지점
        public UInt16 dest;     // 목적지점
        public USE use;

        public enum USE
        {
            USE_NONE,
            USE_TAKEOUT,
            USE_STACK
        }

        public void Clear()
        {
            id = 0;
            source = 0;
            dest = 0;
            use = USE.USE_NONE;
        }
    }
}
