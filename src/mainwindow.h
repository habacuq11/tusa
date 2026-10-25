#pragma once

#include <QMainWindow>

class QMediaPlayer;
class QAudioOutput;
class QLabel;
class QPushButton;
class QSlider;


class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void openFile();
    void ppState();
    void volumeChanged(int value);

private:
    QMediaPlayer* MediaPlayer;
    QAudioOutput* AudioOutput;
    QLabel* trackTitle_;
    QLabel* trackMetadata_;
    QLabel* songInfo_;
    QPushButton* backButton_;
    QPushButton* playButton_;
    QPushButton* nextButton_;
    QSlider* volumeSlider_;
};