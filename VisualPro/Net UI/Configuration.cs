using System;
using System.Collections.Generic;
using System.Runtime.Remoting.Messaging;

namespace VP_Configuration
{
    // Static as multiple classes reference to this configuration object.
    public static class General
    {
        // C - Class, F - Functions, A - Arguments, V - Variables
        // These are `hardwired' for now but Decoder_Tools::SupportedLanguages has a method to ListAvailableLibraries and ListAvailableSyntaxes
        public static string[] signatures =
        { "C", "F", "A", "V" };

        public static List<string> languageHeader = new List<string>();
        public static List<string> languageSyntax = new List<string>();

        public static void AddLanguageHeader(string value)
        { languageHeader.Add(value); }

        public static string GetLanguageHeader(int i)
        {
            if (i < languageHeader.Count) return languageHeader[i];
            return null;
        }

        public static void AddLanguageSyntax(string value)
        { languageSyntax.Add(value); }

        public static string GetLanguageSyntax(int i)
        {
            if (i < languageSyntax.Count && i != -1) return languageSyntax[i];
            return String.Empty;
        }

        public static int CompareLanguageSyntax(int i)
        {
            
            for(int j = 0; j < languageSyntax.Count; j++)
                if(System.Char.ToUpper(languageSyntax[j][0]) == signatures[i][0]) return j;

            return -1;
        }

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