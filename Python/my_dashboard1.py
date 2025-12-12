import streamlit as st
import pandas as pd
import plotly.express as px

# Define the GitHub link to the CSV file
DATA_URL = "https://github.com/alanjones2/CO2/raw/master/data/countries_df.csv"

# Define a function to load the data
# @st.cache(persist=True)
# def load_data():
#     data = pd.read_csv(DATA_URL, usecols=["Entity", "Code", "Year", "Annual CO₂ emissions"])
#     data.rename(columns={"Entity": "Country", "Code": "Country Code", "Annual CO₂ emissions": "Annual CO2 Emissions"}, inplace=True)
#     return data

# # Load the data
# data = load_data()

data = pd.read_csv(DATA_URL, usecols=["Entity", "Code", "Year", "Annual CO₂ emissions"])
data.rename(columns={"Entity": "Country", "Code": "Country Code", "Annual CO₂ emissions": "Annual CO2 Emissions"}, inplace=True)

# Create a slider to select a year
year = st.slider("Select a year", int(data["Year"].min()), int(data["Year"].max()))

# Create a subset of the data for the selected year
year_data = data[data["Year"] == year]

# Create a Plotly Express choropleth map for the selected year
fig = px.choropleth(year_data, locations="Country Code", color="Annual CO2 Emissions", hover_name="Country", range_color=[0, 1200000000], color_continuous_scale=px.colors.sequential.Plasma)

# Add title and axis labels
fig.update_layout(title_text=f"Annual CO2 Emissions by Country in {year}", geo=dict(showframe=False, showcoastlines=False, projection_type='equirectangular'))

# Show the figure
st.plotly_chart(fig, use_container_width=True)