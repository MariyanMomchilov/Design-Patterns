#include <iostream>
#include <cstring>
#include <vector>
#include <string>

class ParagraphRepr
{
private:
    std::vector<std::string> text;

public:
    size_t size() const { return text.size(); }
    void addText(const std::string &t) { text.push_back(t); }
    void print() const
    {
        for (std::string str : text)
            std::cout << str;
        std::cout << '\n';
    }
};

class ParagraphBuilder
{
protected:
    std::string current_paragraph;
    ParagraphRepr obj;

public:
    ParagraphBuilder() : current_paragraph("") {}
    // not abstract, just do something when have to and do not otherwise
    virtual void BuildChar(char c)
    {
        current_paragraph += c;
    }

    virtual void BuildParagraph() {}
};

class PlainTextParagraphBuilder : public ParagraphBuilder
{
public:
    PlainTextParagraphBuilder() {}

    void BuildParagraph() override
    {
        // closing the last paragraph
        if (current_paragraph != "")
        {
            current_paragraph += '\n';
            obj.addText(current_paragraph);
        }
        current_paragraph = "\n";
    }

    ParagraphRepr getObject() const { return obj; }
};

class HTMLParagraphBuilder : public ParagraphBuilder
{
public:
    HTMLParagraphBuilder() {}

    void BuildParagraph() override
    {
        // closing the last paragraph
        if (current_paragraph != "")
        {
            current_paragraph += "</p>";
            obj.addText(current_paragraph);
        }
        current_paragraph = "<p>";
    }

    ParagraphRepr getObject() const { return obj; }
};

class Director
{
private:
    ParagraphBuilder &builder;

    enum Token
    {
        CHAR = 0,
        PARAGRAPH
    };

    Token parseToken(const char *text, size_t &index)
    {
        if (text[index] == '(' && (strlen(text) > index + 2) && text[index + 1] == 'p' && text[index + 2] == ')')
            index += 2;
        else
            return CHAR;
        return PARAGRAPH;
    }

public:
    Director(ParagraphBuilder &_b) : builder(_b) {}

    // passing the objects that forms the product
    void Construct(const char *text)
    {
        Token current_token;
        builder.BuildParagraph();
        for (size_t i = 0; i < strlen(text); i++)
        {
            current_token = parseToken(text, i);
            if (current_token == CHAR)
                builder.BuildChar(text[i]);
            else if (current_token == PARAGRAPH)
                builder.BuildParagraph();
        }
        builder.BuildParagraph();
    }
};

int main()
{

    const char *text = "This is a plain text. (p)Example for the Builder design pattern. (p)The goal is to build paragraph objects for plain text and html";

    //client
    PlainTextParagraphBuilder plainBuilder;
    HTMLParagraphBuilder htmlBuilder;

    //the same Director
    Director plainBuilderDirector(plainBuilder);
    Director htmlBuilderDirector(htmlBuilder);

    plainBuilderDirector.Construct(text);
    htmlBuilderDirector.Construct(text);

    ParagraphRepr obj1, obj2;

    // Different representation
    obj1 = plainBuilder.getObject();
    obj2 = htmlBuilder.getObject();

    obj1.print();
    obj2.print();

    return 0;
}