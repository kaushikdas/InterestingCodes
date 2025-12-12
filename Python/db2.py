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

# Selectbox for countries
countries = st.sidebar.multiselect("Select countries", filtered_df['Entity'].unique())

# Filter data by selected countries
filtered_df = filtered_df[filtered_df['Entity'].isin(countries)]

# Bar chart of CO2 emissions by country
if not filtered_df.empty:
    fig = px.bar(filtered_df, x='Entity', y='Annual CO₂ emissions', title='Annual CO₂ emissions by country')
    st.plotly_chart(fig)
else:
    st.warning("No data available for the selected year and countries.")
