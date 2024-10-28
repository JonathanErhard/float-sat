import serial
import sys
from threading import Thread
import time
import tkinter as tk

port = sys.argv[1]
baud_rate = 115200
ser = serial.Serial(port, baud_rate)

last_update_time = time.time()
scheduled_tasks = {'yellow': None, 'red': None}

def update_lights(canvas, lights, color):
    # Reset all lights to off (grey)
    for light in lights.values():
        canvas.itemconfig(light, fill="grey")
    # Turn on the specified light
    canvas.itemconfig(lights[color], fill=color)

def schedule_light_change(canvas, lights, color, delay):
    global last_update_time
    def change_color():
        # check if the scheduled update is still valid
        if time.time() - last_update_time >= delay / 1000:
            update_lights(canvas, lights, color)

    return canvas.after(delay, change_color)

def read_from_port(ser, text_var, canvas, lights):
    global last_update_time, scheduled_tasks
    while True:
        if ser.in_waiting > 0:
            data = ser.readline().decode('utf-8')[0:-2]
            if "FALSE" in data:
                update_lights(canvas, lights, "red")
            elif "decoded" in data:
                update_lights(canvas, lights, "green")
                char_index = data.find("decoded:") + len("decoded: ")
                char = data[char_index:]
                chars_to_print = data[char_index:char_index+3]
                print(chars_to_print)

                if char:  # Check if char is not empty
                    current_text = text_var.get()
                    text_var.set(current_text + char)
        else:
            update_lights(canvas, lights, "yellow")
        time.sleep(0.1)


def clear_text(text_var):
    text_var.set("")

def create_gui():
    root = tk.Tk()
    root.title("Optical Ground Station (OGS)")
    root.geometry("500x300")

    text_var = tk.StringVar()

    light_frame = tk.Frame(root)
    light_frame.pack(pady=20)

    canvas = tk.Canvas(light_frame, width=180, height=50)
    lights = {
        "red": canvas.create_oval(10, 10, 40, 40, fill="grey"), 
        "yellow": canvas.create_oval(70, 10, 100, 40, fill="grey"),
        "green": canvas.create_oval(130, 10, 160, 40, fill="grey")
    }
    canvas.pack()

    label_frame = tk.Frame(root)
    label_frame.pack(pady=5)

    tk.Label(label_frame, text="Error").pack(side=tk.LEFT, padx=(30, 20))
    tk.Label(label_frame, text="Waiting Data").pack(side=tk.LEFT, padx=10)
    tk.Label(label_frame, text="Receiving").pack(side=tk.LEFT, padx=10)

    label = tk.Label(root, textvariable=text_var)
    label.pack(pady=10)

    clear_button = tk.Button(root, text="Clear Text", command=lambda: clear_text(text_var))
    clear_button.pack(pady=10)

    thread = Thread(target=read_from_port, args=(ser, text_var, canvas, lights))
    thread.daemon = True
    thread.start()

    root.mainloop()

if __name__ == "__main__":
    create_gui()

