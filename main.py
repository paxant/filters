import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from Ui_mainwindow import Ui_MainWindow  # Replace with your generated UI file name

class MyApplication(QMainWindow):
    def __init__(self):
        super().__init__()

        # Create an instance of the UI
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MyApplication()
    window.show()
    sys.exit(app.exec_())