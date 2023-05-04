# This is the Python Mini-Project
# DEVELOPER NAME: PARTH N PATEL
# MENTOR: PROF. SACHIN PATEL


#PROJECT DETAILS:
#PROJECT IS ABOUT MAKING CAMERA MOTION-DETECTOR
#WHICH WILL DETECT ANY KIND OF MOTION AND WILL GIVE THE GRAPH OF IT
#THE GRAPH WILL HAVE LOG OF ENTRY TIME AND EXIT TIME OF THE OBJECTS
#.CSV FILE WILL BE GENERATED FROM motionDetector.py WHICH WILL BE USED BY plotting.py TO CREATE GRAPH

# HOW TO TEST OR RUN THE PROGRAM:
# RUN plotting.py

# THE PROJECT CONTAINS TWO PYTHON FILES
# ONE FOR THE MOTION DETECTION
# OTHER FOR CREATING THE GRAPH

#THIS WILL CREATE THE GRAPH
#LIBRARIES USED IN THIS FILE:
# 1. BOKEH

#Bokeh is a Python library for creating interactive visualizations for modern web browsers. 
#It helps you build beautiful graphics, ranging from simple plots to complex dashboards with streaming datasets


from motionDetector import df  #IMPORTING THE DATAFRAME FROM motionDetector.py

from bokeh.plotting import figure, show, output_file #IMPORTING FROM BOKEH.PLOTTING

from bokeh.models import HoverTool,ColumnDataSource  #IMPORTING FROM BOKEH.MODELS

df["Entry_String"]=df["Entry"].dt.strftime("%Y-%m-%d %H:%M:%S") #ADDING NEW COLUMN TO DATAFRAME IMPORTED
df["Exit_String"]=df["Exit"].dt.strftime("%Y-%m-%d %H:%M:%S")   #ADDING NEW COLUMN TO DATAFRAME IMPORTED

#STRFTIME()- FOR CONVERTING DATETIME OBJECT TO ITS EQUIVALENT STRING

cds=ColumnDataSource(df)
#COLUMNDATASOURCE() FROM BOKEH.MODELS IS USED
#A ColumnDatasource can be considered as a mapping between column name and list of data. 
#A Python dict object with one or more string keys and lists or numpy arrays as values is passed to ColumnDataSource constructor.

p=figure(x_axis_type='datetime',height=300,width=800,title="Motion Graph")
p.ygrid.grid_line_color=None
p.yaxis.visible=False

# above code will not show the y axis as it is not required


#FIGURE() FROM BOKEH.PLOTTING IS USED
# IT IS A SUBCLASS THAT SIMPLIFIES THE PLOT CREATION


hover=HoverTool(tooltips=[("Entry","@Entry_String"),("Exit","@Exit_String")])
#HOVERTOOL() FROM BOKEH.MODELS IS USED 
#IT HELPS IN ENABLING THE HOVERING
p.add_tools(hover) #ADDING IT TO THE TOOLBAR
q=p.quad(left="Entry",right="Exit",bottom=0,top=1,color="green",source=cds)
p.xgrid.visible = False
#QUAD() FROM BOKEH.PLOTTING.FIGURE() IS USED TO PLOT THE QUADLILATERAL IN THE GRAPH


output_file("Graph.html")
#OUTPUT_FILE() IS USED FROM BOKEH
#IT WILL OUTPUT IN .HTML FORM WHICH WILL BE OPENED IN NEW OUTPUT WINDOW
show(p)
#WILL DISPLAY THE FIGURE