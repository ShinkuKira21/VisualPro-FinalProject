namespace VP_Configuration
{
    public static class General
    {
        // C - Class, F - Functions, A - Arguments, V - Variables
        public static string[] signatures =
        { "C", "F", "A", "V"};

        public static int GetLength()
        { return signatures.Length; }

        public static string GetID(int i)
        { return signatures[i]; }

        public static int GetID(string text)
        {
            for (int i = 0; i < signatures.Length; i++)
                if (text[0] == signatures[i][0])
                    return i;

            return -1;
        }

        public static int GetID(char text)
        {
            for (int i = 0; i < signatures.Length; i++)
                if (text == signatures[i][0])
                    return i;

            return -1;
        }
    }
}