using System;
using System.Runtime.InteropServices;

namespace VP_Tools
{
    public class Tools
    {
        protected int[] length;

        public Tools() { }

        public void Increment(int i)
        { length[i]++; }

        public void Decrement(int i)
        { length[i]--; }

        public void SetLength(string[] signatures)
        { length = new int[signatures.Length]; }

        public int GetLength(int i)
        { return length[i]; }

        public bool FindSubStr(char start, char end, int pos, string str, string find)
        {
            int count = 0; bool bStarted = false; string toCheck = string.Empty;

            for (int i = 0; i < str.Length;i++)
            {
                if (!bStarted && str[i] == start && count == pos)
                {
                    bStarted = true; continue;
                }
                
                if (!bStarted && str[i] == start)
                    count++;

                if (bStarted && str[i] != end)
                    toCheck += str[i];

                else if (bStarted)
                    break;
            }

            if (toCheck == find) return true;

            return false;
        }

        public string FindSubStr(char start, char end, int pos, string str)
        {
            int count = 0; string toReturn = ""; bool bStarted = false;

            for (int i = 0; i < str.Length; i++)
            {
                if(!bStarted && str[i] == start && count == pos)
                {
                    bStarted = true; continue;
                }

                if (!bStarted && str[i] == start)
                    count++;

                if (bStarted && str[i] != end)
                    toReturn += str[i];

                else if (bStarted) 
                    break;
            }

            return toReturn;
        }
    }

    public class Cache : Tools
    {
        public Cache() 
        { 
            Obj = null;
            Integer = 0;
            Text = "";
        }

        public object Obj { get; set; }
        public int Integer { get; set; }
        public string Text { get; set; }
    }

    public class Manager : Cache
    {
        protected string[] signatures;
        protected IntPtr[] proPlan, proPlanSigs;
        protected IntPtr ts;

        public Manager(string[] signatures)
        {
            this.signatures = signatures; 
            Initialisation();
        }

        ~Manager() 
        {
            for (int i = 0; i < proPlan.Length; i++)
            {
                VP_Comms.ProgrammingPlanner.DisposeClass(proPlan[i]);
                VP_Comms.Libraries.DisposeTS(proPlanSigs[i]);
            }
               
        }

        public void Initialisation()
        {
            proPlan = new IntPtr[signatures.Length];
            proPlanSigs = new IntPtr[signatures.Length];

            for(int i = 0; i < signatures.Length; i++)
            {
                proPlanSigs[i] = VP_Comms.Libraries.InitialiseTS();
                proPlan[i] = VP_Comms.ProgrammingPlanner.InitialiseClass(proPlanSigs[i], signatures[i]);
            }
                
            SetLength(signatures);
        }

        public void Add(string text, string[] opts /* { Member, DataType, Name, Parent } */)
        {
            int sel = FindSignature(text);
            if(sel == -1) return;

            //Hex to Ascii: [a+] (add)
            VP_Comms.ProgrammingPlanner.CallFunction(proPlan[sel], "612b", opts[0], opts[1], opts[2], opts[3], -1);
            Increment(sel);
        }

        public void Remove(int sel, int id)
        {
            //Hex to Ascii: [rm] (remove)
            VP_Comms.ProgrammingPlanner.CallFunction(proPlan[sel], "726d", null, null, null, null, id);
            Decrement(sel);
        }

        public string GetList(string text)
        {
            int sel = FindSignature(text);

            ts = VP_Comms.Libraries.InitialiseTS();
            string list = Marshal.PtrToStringAnsi(VP_Comms.ProgrammingPlanner.CallStringFunction(proPlan[sel], ts, "List"));

            Console.WriteLine("List:\n");
            Console.WriteLine(list);

            VP_Comms.Libraries.DisposeTS(ts);

           return null;
        }

        public int FindSignature(string text)
        {
            for (int i = 0; i < signatures.Length; i++)
                if (text[0] == signatures[i][0])
                    return i;

            return -1; // error
        }
    }
}