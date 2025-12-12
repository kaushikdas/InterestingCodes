import pandas as pd
import streamlit as st
import plotly.express as px

# Load data from GitHub
url = 'https://github.com/alanjones2/CO2/raw/master/data/countries_df.csv'
df = pd.read_csv(url, usecols=['Entity', 'Code', 'Year', 'Annual CO₂ emissions'])

# Rename columns
df = df.rename(columns={
    'Entity': 'Country',
    'Code': 'Country Code',
    'Annual CO₂ emissions': 'Annual CO2 Emissions'
})

# Create slider for selecting year
min_year = df['Year'].min()
max_year = df['Year'].max()
selected_year = st.slider('Select year', min_value=min_year, max_value=max_year, value=max_year)

# Create selection box for choosing countries
available_countries = sorted(df['Country'].unique())
selected_countries = st.multiselect('Select countries', available_countries, default=available_countries[:5])

# Filter data by selected year and countries
filtered_df = df[(df['Year'] == selected_year) & (df['Country'].isin(selected_countries))]

# Create two columns for displaying choropleth and bar chart
col1, col2 = st.beta_columns(2)

# Plot choropleth using Plotly Express
fig1 = px.choropleth(filtered_df, locations='Country Code', color='Annual CO2 Emissions',
                    hover_name='Country', animation_frame='Year', projection='natural earth',
                    title=f'Annual CO2 Emissions by Country ({selected_year})')
col1.plotly_chart(fig1, use_container_width=True)

# Plot bar chart using Plotly Express
fig2 = px.bar(filtered_df, x='Country', y='Annual CO2 Emissions', color='Country',
             title=f'Annual CO2 Emissions by Country ({selected_year})')
col2.plotly_chart(fig2, use_container_width=True)
