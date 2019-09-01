#ifndef QFORMDOC_H
#define QFORMDOC_H

#include <QWidget>

namespace Ui {
class QFormDoc;
}

class QFormDoc : public QWidget
{
    Q_OBJECT

public:
    explicit QFormDoc(QWidget *parent = nullptr);
    ~QFormDoc();
    void loadFromFiles(QString& aFileName); // 打开文件
    QString currentFileNames(); // 返回当前文件名
    bool isFileOpeneds();// 文件已经打开
    void setEditFonts(); // 设置字体
    void textCuts();// cut
    void textCopys(); // copy
    void textPastes(); // paste

private:
    Ui::QFormDoc *ui;
    QString mCurrentFile; //　当前的文件
    bool mFileOpened = false; // 文件已打开



};

#endif // QFORMDOC_H
