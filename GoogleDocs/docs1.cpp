#include <bits/stdc++.h>
using namespace std;
class DocumentEditor
{
private:
    vector<string> docElems;
    string renderedDocument;

public:
    void addText(string text)
    {
        docElems.push_back(text);
    }

    void addImage(string path)
    {
        docElems.push_back(path);
    }

    string renderDocument()
    {
        string doc;
        for (auto el : docElems)
        {
            string temp;
            if (el.size() > 4 && (el.substr(el.size() - 4) == ".jpg" || el.substr(el.size() - 4) == ".png"))
            {
                temp = "[Image: = " + el + "]" + "\n";
            }
            else
            {
                temp = "[Text: = " + el + "]" + "\n";
            }
            doc += temp;
        }
        renderedDocument = doc;
        return renderedDocument;
    }

    void saveToFile()
    {
        ofstream file("Doc1.txt");
        if (file.is_open())
        {
            // file << renderDocument();
            file << renderedDocument;
            cout << "Saved to File System" << endl;
        }
        else
        {
            cout << "Error : File not found" << endl;
        }
    }
};

int main()
{
    DocumentEditor de;
    de.addText("hi i am abhishek");
    de.addImage("Img.png");
    de.addText("hi This is test 1");
    cout << de.renderDocument() << endl;
    de.saveToFile();
}