#include <bits/stdc++.h>
using namespace std;

class DocElement
{
public:
    virtual string render() = 0;
};

// section of document element

class TextElement : public DocElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        string temp = "[Text: = " + text + "]" + "\n";
        return temp;
    }
};

class ImageElement : public DocElement
{
private:
    string path;

public:
    ImageElement(string path)
    {
        this->path = path;
    }
    string render() override
    {
        string temp = "[Image: = " + path + "]" + "\n";
        return temp;
    }
};

// section of document

class Document
{
private:
    vector<DocElement *> elements;

public:
    void addElement(DocElement *el)
    {
        elements.push_back(el);
    }

    string render()
    {
        string renderedDocument;
        for (auto el : elements)
        {
            renderedDocument += el->render();
        }
        return renderedDocument;
    }
};

// persitance areeaa

class Persistance
{
public:
    virtual void save(string filee) = 0;
};

class SaveToFile : public Persistance
{
public:
    void save(string filee) override
    {
        ofstream file("Doc1.txt");
        if (file.is_open())
        {
            file << filee;
            cout << "Saved to File System" << endl;
        }
        else
        {
            cout << "Error : File not found" << endl;
        }
    }
};

class DocumentEditor
{
private:
    Document doc;
    Persistance *db;
    string renderedDocument;

public:
    DocumentEditor(Persistance *db)
    {
        this->db = db;
    }
    void addText(string el)
    {
        TextElement *te = new TextElement(el);
        doc.addElement(te);
    }

    void addImage(string path)
    {
        ImageElement *im = new ImageElement(path);
        doc.addElement(im);
    }

    string renderDocument()
    {
        return doc.render();
    }

    void saveToFile()
    {
        db->save(doc.render());
    }
};

int main()
{
    Persistance *db = new SaveToFile();
    DocumentEditor de(db);
    de.addText("hi i am abhishek");
    de.addImage("Img.png");
    de.addText("hi This is test 1");
    cout << de.renderDocument() << endl;
    de.saveToFile();
}