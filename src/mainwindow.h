#pragma once

#include <QMainWindow>

class QMediaPlayer;
class QAudioOutput;
class QLabel;


class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void openFile();

private:
    QMediaPlayer* MediaPlayer;
    QAudioOutput* AudioOutput;
    QLabel* trackTitle_;
    QLabel* trackMetadata_;
    QLabel* songInfo_;
};