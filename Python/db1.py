import streamlit as st
import pandas as pd
import plotly.express as px

# Load data
url = 'https://github.com/alanjones2/CO2/raw/master/data/countries_df.csv'
df = pd.read_csv(url, usecols=['Entity', 'Year', 'Code', 'Annual CO₂ emissions'])

# Sidebar year selection
year_range = st.sidebar.slider("Select year", min_value=int(df['Year'].min()), max_value=int(df['Year'].max()), value=int(df['Year'].max()))

# Filter data by year
filtered_df = df[df['Year'] == year_range]

# Plotly Express choropleth
fig = px.choropleth(filtered_df, locations='Code', color='Annual CO₂ emissions', 
                    hover_name='Entity', animation_frame='Year', 
                    range_color=[0, filtered_df['Annual CO₂ emissions'].max()], 
                    title='Annual CO₂ emissions by country')
fig.update_layout(geo=dict(showframe=False, showcoastlines=False))
st.plotly_chart(fig)
